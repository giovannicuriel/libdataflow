#include "DefaultPipeline.hpp"
#include "DefaultPipelineBuilder.hpp"

void DefaultPipelineBuilder::clear() {
    for (AbstractTask * task : mTasks) {
        delete task;
    }
    mTasks.clear();
}

void DefaultPipelineBuilder::addTask(AbstractTask * task) {
    mTasks.push_back(task);
}


PipelineInterface * DefaultPipelineBuilder::build() {
    DefaultPipeline * ret = new DefaultPipeline();
    for (AbstractTask * currTask : mTasks) {
        ret->addTask(currTask);
    }
    return ret;
}
