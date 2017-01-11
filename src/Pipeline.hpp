/*
 * Pipeline.hpp
 *
 *  Created on: 11 de jan de 2017
 *      Author: giovanni
 */

#ifndef PIPELINE_HPP_
#define PIPELINE_HPP_

#include <vector>
#include <uuid/uuid.h>
#include "AbstractTask.hpp"

/** This could be an interface - PipelineManager should be responsible for creating real pipelines*/

class Pipeline {
public:
    Pipeline();
    virtual ~Pipeline();

    uint32_t addTask(AbstractTask * task);

    uint32_t start();
    uint32_t resume();
    uint32_t rollback();

    inline uuid_t getUuid() { return mUuid; }

protected:
    // In the future, this could be a tree
    std::vector<AbstractTask *> mTasks;
    uuid_t mUuid;
};

#endif /* PIPELINE_HPP_ */
