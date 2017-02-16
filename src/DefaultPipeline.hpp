#ifndef DEFAULT_PIPELINE_HPP
#define DEFAULT_PIPELINE_HPP

#include <vector>
#include "ManagedPipelineInterface.hpp"

class DefaultPipeline : public ManagedPipelineInterface {
public:
    virtual PipelineReturn addTask(AbstractTask * task) override;
    virtual PipelineReturn start() override;
    virtual PipelineReturn resume() override;
    virtual PipelineReturn rollback() override;
};

#endif // DEFAULT_PIPELINE_HPP

