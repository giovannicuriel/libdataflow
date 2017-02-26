#include <iostream>
#include <tuple>
#include "Task.hpp"
#include "MirroredValue.hpp"
#include "DefaultPipelineBuilder.hpp"
#include "Lockable.hpp"

class Source : public Task<int, std::tuple<int, int>> {
public:
    AbstractTask::Status prepare() override { return AbstractTask::Status::OK; }
    AbstractTask::Status finish() override { return AbstractTask::Status::OK; }
    AbstractTask::Status undo() override { return AbstractTask::Status::OK; }
    AbstractTask::Status execute() override { 
        std::get<0>(outputParameter()) = 10;
        std::get<1>(outputParameter()) = 40;
        return AbstractTask::Status::OK;
    };
};


class Sum : public Task<std::tuple<int, int>, int> {
public:
    AbstractTask::Status prepare() override { return AbstractTask::Status::OK; }
    AbstractTask::Status finish() override { return AbstractTask::Status::OK; }
    AbstractTask::Status undo() override { return AbstractTask::Status::OK; }
    AbstractTask::Status execute() override { 
        outputParameter = std::get<0>(*inputParameter) + std::get<1>(*inputParameter);
        return AbstractTask::Status::OK;
    };
};
class Printer : public Task<int, int> {
public:
    AbstractTask::Status prepare() override { return AbstractTask::Status::OK; }
    AbstractTask::Status finish() override { return AbstractTask::Status::OK; }
    AbstractTask::Status undo() override { return AbstractTask::Status::OK; }
    Printer() = default;
    AbstractTask::Status execute() override { 
        std::cout << "Results: " << *inputParameter << std::endl;
        return AbstractTask::Status::OK;
    };
};


int main(void) {
    Source t1;
    Sum t2;
    Printer t3;

    t1.setNext(t2);
    t2.setNext(t3);

    PipelineBuilderInterface * builder = new DefaultPipelineBuilder();
    builder->addTask(&t1);
    builder->addTask(&t2);
    builder->addTask(&t3);

    PipelineInterface * pipeline = builder->build();

    pipeline->start();

    MirroredValue<int> v1, v2;
    v1.setReflection(v2);

    v1 = 10;
    std::cout << *v2 << std::endl;

    Lockable<int> teste;
    teste.lock();
    (*teste) = 10;
    teste.unlock();

    return 0;
}
