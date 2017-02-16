#ifndef PIPELINE_BUILDER_HPP
#define PIPELINE_BUILDER_HPP

#include "AbstractTask.hpp"
#include "PipelineInterface.hpp"


class PipelineBuilderInterface {
public:
    virtual void clear() = 0;
    virtual void addTask(AbstractTask * task) = 0;
    virtual PipelineInterface * build() = 0;
};


#endif // PIPELINE_BUILDER_HPP

