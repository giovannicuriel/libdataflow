#ifndef ABSTRACT_TASK_HPP
#define ABSTRACT_TASK_HPP

/**
 * Possible return values for AbstractTask methods
 */
enum class TaskReturn {
    OK,     ///< The method was executed successfully and completely
    FAILED, ///< The method has failed
    LATER   ///< The method is OK so far, but it will finish later.
};


/**
 * Class representing a generic task.
 */
class AbstractTask {
public:
    AbstractTask() = default;
    AbstractTask(const AbstractTask &) = delete;
    AbstractTask(AbstractTask &&) = delete;
    virtual ~AbstractTask() = default;
    AbstractTask & operator=(const AbstractTask &) = delete;

    /**
     * Prepare task for execution.
     * This method should be called before 'execute()' method.
     * @return The results of this preparation.
     */
    virtual TaskReturn prepare() = 0;
    
    
    /**
     * Actually do what this task is intend to do.
     * @return Status of execution.
     */
    virtual TaskReturn execute() = 0;
    
    /**
     * Finish the execution of this task.
     * This method is executed whether the task has succeeded or not.
     * @return Status of execution of this method.
     */
    virtual TaskReturn finish() = 0;
    
    /**
     * Undo everything that this task did.
     * 
     * In case of rolling back, this method will be called. This time
     * no extra method should not be called (such as prepare() or 
     * finish()
     * 
     * @return Status of execution.
     */ 
    virtual TaskReturn undo() { return TaskReturn::OK; }
};

#endif
