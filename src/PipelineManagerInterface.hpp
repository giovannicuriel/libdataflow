#ifndef PIPELINE_MANAGER_INTERFACE_HPP
#define PIPELINE_MANAGER_INTERFACE_HPP

#include "PipelineInterface.hpp"
#include "PipelineNotification.hpp"

/**
 * Class responsible for managing execution of many pipelines.
 */
class PipelineManagerInterface {
public:

    enum class Status {
        OK,
        NOT_FOUND
    };

    /**
     * Add a new pipeline to be managed.
     * @param pipeline The pipeline to be managed
     */
    virtual Status addPipeline(PipelineInterface * pipeline) = 0;

    /**
     * Start the execution of a pipeline.
     * @param pipeid The pipeline identifier to be started
     */
    virtual Status startPipeline(PipeId pipeid) = 0;

    /**
     * Stop the execution of a pipeline.
     * The execution will stop as soon as the current task finishes.
     * @param pipeid The pipeline identifier to be stopped
     */
    virtual Status stopPipeline(PipeId pipeid) = 0;

    /**
     * Resume the execution of a pipeline.
     * @param pipeid The pipeline identifier to be started
     */
    virtual Status resumePipeline(PipeId pipeid) = 0;

    /**
     * Indicate that a particular pipeline should receive a notification soon.
     * The notification ID should be given by the user.
     * @param pipeid The pipeline identifier
     * @param notification The structure to be used when notification arrives.
     */
    virtual Status registerPipelineNotification(PipeId pipeid, PipelineNotification * notification) = 0;

    /**
     * Notify a pipeline that something happened.
     * @param pipeid The pipeline to be notified.
     * @param notifid The notification ID previously registered 
     * @param data The notification data
     */
    virtual Status notifyPipeline(PipeId pipeid, PipeId notifid, PipelineNotificationData * data) = 0;
};


#endif // PIPELINE_MANAGER_INTERFACE_HPP

