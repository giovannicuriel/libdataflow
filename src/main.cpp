#include <iostream>
#include <tuple>
#include "Task.hpp"
#include "MirroredValue.hpp"

class Source : public Task<int, std::tuple<int, int>> {
public:
    int32_t execute() override { 
        std::get<0>(outputParameter()) = 10;
        std::get<1>(outputParameter()) = 40;
        return 0;
    };
};


class Sum : public Task<std::tuple<int, int>, int> {
public:
    int32_t execute() override { 
        outputParameter = std::get<0>(*inputParameter) + std::get<1>(*inputParameter);
        return 0;
    };
};
class Printer : public Task<int, int> {
public:
    Printer() = default;
    int32_t execute() override { 
        std::cout << "Results: " << *inputParameter << std::endl;
        return 0;
    };
};


int main(void) {
    Source t1;
    Sum t2;
    Printer t3;
    
    t1.setNext(t2);
    t2.setNext(t3);
    
    t1.prepare();
    t1.execute();
    t1.finish();
    t2.prepare();
    t2.execute();
    t2.finish();
    t3.prepare();
    t3.execute();
    t3.finish();
    
    MirroredValue<int> v1, v2;
    v1.setReflection(v2);
    
    v1 = 10;
    std::cout << *v2 << std::endl;
    
    return 0;
}
