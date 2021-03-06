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
    /**
     * Set the next task in the queue.
     * The current output parameter must be the same type as the input parameter
     * from the next one.
     * @param next The next task.
     * @Status Status::OK
     */
    template<typename X>
    AbstractTask::Status setNext(Task<OutputParameter, X> & next);

    /**
     * Status a reference to the input parameter
     * @Status a reference to the input parameter.
     */
    MirroredValue<InputParameter> & getInputParameter() { return inputParameter; }

protected:
    MirroredValue<InputParameter> inputParameter;
    MirroredValue<OutputParameter> outputParameter;
};

template<typename InputParameter, typename OutputParameter>
template<typename T>
AbstractTask::Status Task<InputParameter, OutputParameter>::setNext(Task<OutputParameter, T> & next) {
    outputParameter.setReflection(next.getInputParameter());
    return AbstractTask::Status::OK;
}


#endif
