#ifndef PIPELINE_MANAGER_HPP
#define PIPELINE_MANAGER_HPP

#include <map>
#include <thread>
#include <mutex>
#include <queue>
#include <semaphore.h>
#include "PipelineInterface.hpp"
#include "PipelineManagerInterface.hpp"
#include "Lockable.hpp"

/**
 * Default implementation for pipeline manager
 */
class PipelineManager : public PipelineManagerInterface {
public:

    PipelineManager();

    PipelineManagerInterface::Status addPipeline(PipelineInterface * pipeline) override;

    PipelineManagerInterface::Status startPipeline(PipeId pipeid) override;

    PipelineManagerInterface::Status stopPipeline(PipeId pipeid) override;

    PipelineManagerInterface::Status resumePipeline(PipeId pipeid) override;

    PipelineManagerInterface::Status registerPipelineNotification(PipeId pipeid, PipelineNotification * notification) override;

    PipelineManagerInterface::Status notifyPipeline(PipeId pipeid, PipeId notifid, PipelineNotificationData * data) override;

protected:

    void executePipelineMgr();

    std::map<PipeId, PipelineInterface *> mPipelines;
    std::thread mExecutor;
    Lockable<std::queue<PipeId>> mPipelineQueue;
    sem_t mSem;
    bool mIsRunning;
};

#endif /* PIPELINE_MANAGER_HPP */

