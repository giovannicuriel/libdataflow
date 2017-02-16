#ifndef MANAGED_PIPELINE_HPP_
#define MANAGED_PIPELINE_HPP_

#include "PipelineInterface.hpp"

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
class ManagedPipelineInterface : public PipelineInterface {
public:
    /**
     * Resumes the execution for this pipeline.
     * The return code of this method doesn't mean that the pipeline
     * finished its execution successfully, but rather it was
     * successfully resumed.
     * @retval PipelineReturn::OK If the pipeline was resumed successfully.
     */
    virtual PipelineReturn resume() = 0;

    /**
     * Rolls back the execution of this pipeline.
     * If any error occurs, then this method could be called to undo all
     * the operations that the tasks performed.
     * @retval PipelineReturn::OK If the pipeline rollback was successfully initiated.
     */
    virtual PipelineReturn rollback() = 0;
};

#endif /* MANAGED_PIPELINE_HPP_ */
