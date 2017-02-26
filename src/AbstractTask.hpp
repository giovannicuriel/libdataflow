#ifndef ABSTRACT_TASK_HPP
#define ABSTRACT_TASK_HPP

/**
 * @class Class representing a generic task.
 */
class AbstractTask {
public:

    /**
     * Possible Status values for AbstractTask methods
     */
    enum class Status {
        OK,     ///< The method was executed successfully and completely
        FAILED, ///< The method has failed
        LATER   ///< The method is OK so far, but it will finish later.
    };


    AbstractTask() = default;
    AbstractTask(const AbstractTask &) = delete;
    AbstractTask(AbstractTask &&) = delete;
    virtual ~AbstractTask() = default;
    AbstractTask & operator=(const AbstractTask &) = delete;

    /**
     * Prepare task for execution.
     * This method should be called before 'execute()' method.
     * @Status The results of this preparation.
     */
    virtual Status prepare() = 0;


    /**
     * Actually do what this task is intend to do.
     * @Status Status of execution.
     */
    virtual Status execute() = 0;

    /**
     * Finish the execution of this task.
     * This method is executed whether the task has succeeded or not.
     * @Status Status of execution of this method.
     */
    virtual Status finish() = 0;

    /**
     * Undo everything that this task did.
     *
     * In case of rolling back, this method will be called. This time
     * no extra method should not be called (such as prepare() or
     * finish()
     *
     * @Status Status of execution.
     */
    virtual Status undo() = 0;
};

#endif
