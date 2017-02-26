#ifndef LOCKABLE_HPP_
#define LOCKABLE_HPP_

#include <mutex>


/**
 * Template class for lockable variables.
 * This class will add a 'lockable' feature to a particular variable, 
 * so that it will be able to be atomically written and read.
 */
template<typename T>
class Lockable {
public:
    Lockable();
    virtual ~Lockable();
    
    /**
     * operator* overload.
     * To access the actual value of this object, the user should access
     * just like a pointer: (*var) = 10;
     */
    T & operator*();
    
    
    /**
     * Lock this variable
     */
    void lock();
    
    /**
     * Unlock this variable
     */
    void unlock();
    
    /**
     * Exception in case of use without locking. So be careful.
     */
    struct Exception {
        int code;
    };
    
protected:

    /**
     * The mutex protecting this variable
     */
    std::mutex mMutex;
    
    /**
     * Flag indicating whether this variable is locked or not.
     */
    bool isLocked;
    
    /**
     * The actual data
     */
    T mData;
};

template<typename T>
Lockable<T>::Lockable() : isLocked(false) {
}

template<typename T>
Lockable<T>::~Lockable() {
    // Unlock the mutex??
}

template<typename T>
T & Lockable<T>::operator*() {
    if (isLocked == false) {
        throw new Lockable::Exception();
    }
    return mData;
}

template<typename T>
void Lockable<T>::lock() {
    mMutex.lock();
    isLocked = true;
}

template<typename T>
void Lockable<T>::unlock() {
    isLocked = false;
    mMutex.unlock();
}

#endif
