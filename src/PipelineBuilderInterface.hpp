#ifndef PIPELINE_BUILDER_HPP
#define PIPELINE_BUILDER_HPP

#include "AbstractTask.hpp"
#include "PipelineInterface.hpp"

/**
 * Interface for pipeline builders
 * These objects will be the repsonsible for creating
 * new pipelines.
 */
class PipelineBuilderInterface {
public:
    /**
     * Empty the pipeline
     */
    virtual void clear() = 0;

    /**
     * Add a new task to the pipeline.
     * No assumptions are made to what happens
     * to the task passed as a parameter.
     * @param task The new task to be added.
     */
    virtual void addTask(AbstractTask * task) = 0;

    /**
     * Build the pipeline.
     * It is up to the user to deallocate this
     * object after calling this method.
     * @Status A reference to a new pipeline.
     */
    virtual PipelineInterface * build() = 0;
};


#endif // PIPELINE_BUILDER_HPP

