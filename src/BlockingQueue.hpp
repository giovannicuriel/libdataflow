#ifndef BLOCKING_QUEUE_HPP_
#define BLOCKING_QUEUE_HPP_

#include <semaphore.h>
#include <queue>

/**
 * Class implementing a blocking queue.
 * This class will block all pop() operations until a push() is
 * performed.
 */
template<typename T>
class BlockingQueue {
public:
    enum class Status {
        OK,
        FAILURE
    };

    BlockingQueue();
    virtual ~BlockingQueue();
    
    /**
     * @brief Push an item to the queue.
     * This method will add an item to the queue.
     * If there is an element blocked while consuming an element, it 
     * will be released.
     * @param item The item to be added. In fact, a copy of this object
     * will be added to the queue.
     */
    Status pushBack(T & item);
    
    
    /**
     * @brief Retrieve an item from the front of the queue.
     * @retval OK If everything is ok
     * @retval FAILURE If this queue is no longer valid and the queue is 
     * currently being destroyed.
     */
    Status popFront(T & item);
protected:

    /**
     * The actual queue being blocked/released
     */
    std::queue<T> mData;
    
    /**
     * The semaphore protecting this queue.
     */
    sem_t mSemaphore;
    
    /**
     * Flag indicating whether this queue is still valid, i.e.,
     * it has a valid semaphore.
     */
    Lockable<bool> isValid;
};

template<typename T>
BlockingQueue::BlockingQueue() : mData() {
    sem_init(&mSemaphore, 0, 0);
    isValid.lock();
    (*isValid) = true;
    isValid.unlock();
}

template<typename T>
BlockingQueue::~BlockingQueue() {
    isValid.lock();
    
    int ntasks = 0;
    int ret = sem_getvalue(&mSemaphore, &ntasks);
    
    // Free all blocked threads
    while (ntasks < 0) {
        sem_post(&mSemaphore);
        ++ntasks;
    }
    
    (*isValid) = false;
    isValid.unlock();
}

template<typename T>
BlockingQueue::Status BlockingQueue::pushBack(T & item) {
    isValid.lock();
    if ((*isValid) == true) {
        mData.push(item);
        sem_post(&mSemaphore);
    }
    isValid.unlock();
};

template<typename T>
BlockingQueue::Status BlockingQueue::popFront(T & item) {
    sem_wait(&mSemaphore);
    isValid.lock();
    if ((*isValid) == true) {
        item = mData.front();
        mData.pop();
    }
    isValid.unlock();
};

#endif
