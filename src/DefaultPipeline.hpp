#ifndef DEFAULT_PIPELINE_HPP
#define DEFAULT_PIPELINE_HPP

#include <vector>
#include "PipelineInterface.hpp"

/**
 * Default implementation of PipelineInterface
 */
class DefaultPipeline : public PipelineInterface {
public:
    /**
     * @see PipelineInterface::addTask
     */
    virtual PipelineInterface::Status addTask(AbstractTask * task) override;

    /**
     * @see PipelineInterface::addTask
     */
    virtual PipelineInterface::Status start() override;

    /**
     * @see PipelineInterface::addTask
     */
    virtual PipelineInterface::Status resume() override;

    /**
     * @see PipelineInterface::addTask
     */
    virtual PipelineInterface::Status rollback() override;
};

#endif // DEFAULT_PIPELINE_HPP

