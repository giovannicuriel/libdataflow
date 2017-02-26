#include "DefaultPipeline.hpp"

PipelineInterface::Status DefaultPipeline::addTask(AbstractTask * task) {
    mTasks.push_back(task);
    return PipelineInterface::Status::OK;
}

PipelineInterface::Status DefaultPipeline::start() {
    AbstractTask::Status ret;
    for (auto currTask : mTasks) {
        ret = currTask->prepare();
        ret = currTask->execute();
        if (ret == AbstractTask::Status::LATER) {
            // Add to the queue.
        }
        ret = currTask->finish();
    }
    return PipelineInterface::Status::OK;
}

PipelineInterface::Status DefaultPipeline::resume() {
    //@todo
    return PipelineInterface::Status::OK;
}

PipelineInterface::Status DefaultPipeline::rollback() {
    //@todo
    return PipelineInterface::Status::OK;
}


