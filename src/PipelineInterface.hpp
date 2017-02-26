#ifndef PIPELINE_INTERFACEHPP_
#define PIPELINE_INTERFACEHPP_

#include <stdint.h>
#include <vector>
#include "DataflowTypes.hpp"
#include "AbstractTask.hpp"

/**
 * Interface representing a pipeline.
 *
 * Using this interface should be pretty simple:
 *  - Add tasks to this pipeline
 *  - Call start()
 *
 *  And that's it. Depending on the implementation, the tasks could be performed
 *  right away, or it could create a new thread and start the task on it.
 */
class PipelineInterface {
public:

    /**
     * All Status codes available to this interface
     */
    enum class Status {
        OK
    };
    
    /**
     * Adds a new task to the pipeline
     * @param task A reference to the task to be added
     * @retval Status::OK If everything is OK
     */
    virtual Status addTask(AbstractTask * task) = 0;

    /**
     * Starts the execution for this pipeline.
     * The Status code of this method doesn't mean that the pipeline
     * finished its execution successfully, but rather it was
     * successfully initiated.
     * @retval Status::OK If the pipeline was started successfully.
     */
    virtual Status start() = 0;

    /**
     * Resumes the execution for this pipeline.
     * The Status code of this method doesn't mean that the pipeline
     * finished its execution successfully, but rather it was
     * successfully resumed.
     * @retval Status::OK If the pipeline was resumed successfully.
     */
    virtual Status resume() = 0;

    /**
     * Rolls back the execution of this pipeline.
     * If any error occurs, then this method could be called to undo all
     * the operations that the tasks performed.
     * @retval Status::OK If the pipeline rollback was successfully initiated.
     */
    virtual Status rollback() = 0;

    /**
     * Statuss the universal unique identifier of this pipeline.
     * @Status The ID.
     */
    inline void getId(PipeId & id) { id = mId; }

protected:
    // @todo In the future, the pipeline could be modeled
    // as a tree so that branches could be executed.
    std::vector<AbstractTask *> mTasks;
    PipeId mId;
};

#endif /* PIPELINE_INTERFACEHPP_ */
