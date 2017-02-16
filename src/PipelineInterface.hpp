#ifndef PIPELINE_INTERFACEHPP_
#define PIPELINE_INTERFACEHPP_

#include <vector>
#include <uuid/uuid.h>
#include "AbstractTask.hpp"

/**
 * All return codes available to this interface
 */
enum class PipelineReturn {
    OK
};

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
     * Adds a new task to the pipeline
     * @param task A reference to the task to be added
     * @retval PipelineReturn::OK If everything is OK
     */
    virtual PipelineReturn addTask(AbstractTask * task) = 0;

    /**
     * Starts the execution for this pipeline.
     * The return code of this method doesn't mean that the pipeline
     * finished its execution successfully, but rather it was
     * successfully initiated.
     * @retval PipelineReturn::OK If the pipeline was started successfully.
     */
    virtual PipelineReturn start() = 0;

    /**
     * Returns the universal unique identifier of this pipeline.
     * @return The ID.
     */
    inline void getUuid(uuid_t & copy) { uuid_copy(copy, mUuid); }

protected:
    // @todo In the future, the pipeline could be modeled
    // as a tree so that branches could be executed.
    std::vector<AbstractTask *> mTasks;
    uuid_t mUuid;
};

#endif /* PIPELINE_INTERFACEHPP_ */
