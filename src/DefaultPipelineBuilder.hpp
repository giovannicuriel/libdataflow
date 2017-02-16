#ifndef DEFAULT_PIPELINE_BUILDER_HPP
#define DEFAULT_PIPELINE_BUILDER_HPP

#include <vector>

#include "PipelineBuilderInterface.hpp"

class DefaultPipelineBuilder : public PipelineBuilderInterface {
    virtual void clear() override;
    virtual void addTask(AbstractTask * task) override;
    virtual PipelineInterface * build() override;
protected:
    std::vector<AbstractTask *> mTasks;
};

#endif // DEFAULT_PIPELINE_BUILDER_HPP
