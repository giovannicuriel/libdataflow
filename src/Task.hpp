#ifndef TASK_HPP
#define TASK_HPP

#include "AbstractTask.hpp"
#include "MirroredValue.hpp"

/**
 * Class representing an abstract task that has input and output parameters
 */
template<typename InputParameter, typename OutputParameter>
class Task: public AbstractTask {
public:
    template<typename X>
    int32_t setNext(Task<OutputParameter, X> & next);

    virtual TaskReturn prepare() override { return TaskReturn::OK; };
    virtual TaskReturn execute() override { return TaskReturn::OK; };
    virtual TaskReturn finish() override { return TaskReturn::OK; };

    MirroredValue<InputParameter> & getInputParameter() { return inputParameter; }

protected:
    MirroredValue<InputParameter> inputParameter;
    MirroredValue<OutputParameter> outputParameter;
};

template<typename InputParameter, typename OutputParameter>
template<typename T>
int32_t Task<InputParameter, OutputParameter>::setNext(Task<OutputParameter, T> & next) {
    outputParameter.setReflection(next.getInputParameter());
    return 0;
};


#endif
