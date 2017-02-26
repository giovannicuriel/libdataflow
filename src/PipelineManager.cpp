#include <functional>
#include "PipelineManager.hpp"

PipelineManager::PipelineManager() : mPipelines(), mExecutor(std::bind(&PipelineManager::executePipelineMgr, this)) {
    sem_init(&mSem, 0, 0);
    mIsRunning = true;
}

PipelineManagerInterface::Status PipelineManager::addPipeline(PipelineInterface * pipeline) {
    PipeId id;
    pipeline->getId(id);
    mPipelines[id] = pipeline;
    return PipelineManagerInterface::Status::OK;
}

PipelineManagerInterface::Status PipelineManager::startPipeline(PipeId pipeid) {
    /*mPipelineQueue.lock();
    (*mPipelineQueue).push(pipeid);
    mPipelineQueue.unlock();
    sem_post(& mSem);*/
    return PipelineManagerInterface::Status::OK;
}

PipelineManagerInterface::Status PipelineManager::stopPipeline(PipeId pipeid) {
    return PipelineManagerInterface::Status::OK;
}

PipelineManagerInterface::Status PipelineManager::resumePipeline(PipeId pipeid) {
    return PipelineManagerInterface::Status::OK;
}

PipelineManagerInterface::Status PipelineManager::registerPipelineNotification(PipeId pipeid, PipelineNotification * notification) {
    return PipelineManagerInterface::Status::OK;
}

PipelineManagerInterface::Status PipelineManager::notifyPipeline(PipeId pipeid, PipeId notifid, PipelineNotificationData * data) {
    return PipelineManagerInterface::Status::OK;
}

void PipelineManager::executePipelineMgr() {
    while (mIsRunning) {
        sem_wait(& mSem);
        // Execute;
    }
}
