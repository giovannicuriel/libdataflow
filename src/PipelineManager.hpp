#ifndef PIPELINE_MANAGER_HPP
#define PIPELINE_MANAGER_HPP



// This class should be responsible for creating threads and managing all
// errors that might appear during this execution.
class PipelineManager {
public:
    PipelineManager();
    virtual ~PipelineManager();


    int addPipeline(Pipeline * pipeline);
    int startPipeline();

    int resumePipeline(uuit_t uuid);
};

#endif /* PIPELINE_MANAGER_HPP */
