#ifndef PIPELINE_MANAGER_HPP
#define PIPELINE_MANAGER_HPP

#include "PipelineInterface.hpp"

class PipelineManager {
public:
    PipelineManager();
    virtual ~PipelineManager();


    int addPipeline(PipelineInterface * pipeline);
    int startPipeline();

    int resumePipeline(uuit_t uuid);
};

#endif /* PIPELINE_MANAGER_HPP */
