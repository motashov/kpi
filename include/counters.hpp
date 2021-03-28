#pragma once
#include <iostream>
#include <atomic>


//Abstract base class
class Counter{
    protected:
        std::uint64_t _defaultValue;
        std::atomic<std::uint64_t> _value;
    public:
        std::uint64_t dump();
        virtual void set(std::uint64_t n) = 0;
        std::uint64_t get();
        Counter();
        virtual ~Counter();
};

#include "counters/minCounter.hpp"
#include "counters/maxCounter.hpp"
#include "counters/cumulativeCounter.hpp"
#include "counters/ordinaryCounter.hpp"
