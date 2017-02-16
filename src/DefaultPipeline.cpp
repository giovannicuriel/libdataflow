#include "DefaultPipeline.hpp"

PipelineReturn DefaultPipeline::addTask(AbstractTask * task) {
    mTasks.push_back(task);
    return PipelineReturn::OK;
}

PipelineReturn DefaultPipeline::start() {
    for (auto currTask : mTasks) {
        currTask->execute();
    }
    return PipelineReturn::OK;
}

PipelineReturn DefaultPipeline::resume() {
    //@todo
    return PipelineReturn::OK;
}

PipelineReturn DefaultPipeline::rollback() {
    //@todo
    return PipelineReturn::OK;
}


