#ifndef PIPELINE_NOTIFICATION_HPP
#define PIPELINE_NOTIFICATION_HPP

#include <stdint.h>
#include "DataflowTypes.hpp"
#include "PipelineInterface.hpp"

/**
 * Structure supposed to hold all notification data payload.
 * This structure must be inherited by implementations so 
 * that it contain all the necessary data.
 */
struct PipelineNotificationData {
};

/**
 * Structure used to notify pipelines.
 */
struct PipelineNotification {
    PipeId notifId;
    virtual void notify(PipelineNotificationData * data) = 0;
};



#endif // PIPELINE_NOTIFICATION_HPP

