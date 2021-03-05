#include <iostream>
#include <atomic>
#include <stdint.h>


#include "counters/minCounter.hpp"
#include "counters/maxCounter.hpp"
#include "counters/cumulativeCounter.hpp"
#include "counters/ordinaryCounter.hpp"

//Abstract base class
template <class T>
class Counter{
    protected:
        T _defaultValue;
        std::atomic<T> _value;
    public:
        T dump();
        virtual void set(T n) = 0;
        T get();
};

