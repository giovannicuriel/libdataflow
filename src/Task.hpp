#ifndef TASK_HPP
#define TASK_HPP

#include "AbstractTask.hpp"
#include "MirroredValue.hpp"



template<typename InputParameter, typename OutputParameter>
class Task: public AbstractTask {
public:
    template<typename X>
    int32_t setNext(Task<OutputParameter, X> & next);
    
    virtual int32_t prepare() override { return 0; };
    virtual int32_t execute() override { return 0; };
    virtual int32_t finish() override { return 0; };
    
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
