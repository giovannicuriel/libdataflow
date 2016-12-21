#ifndef ABSTRACT_TASK_HPP
#define ABSTRACT_TASK_HPP
#include <unistd.h>

class AbstractTask {
public:
    AbstractTask() = default;
    AbstractTask(const AbstractTask &) = delete;
    AbstractTask(AbstractTask &&) = delete;
    virtual ~AbstractTask() = default;
    AbstractTask & operator=(const AbstractTask &) = delete;

    virtual int32_t prepare() = 0;
    virtual int32_t execute() = 0;
    virtual int32_t finish() = 0;
    virtual int32_t undo() { return 0; }
};

#endif
