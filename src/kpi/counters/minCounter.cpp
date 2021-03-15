#include "counters.hpp"

void MinCounter::set(std::uint64_t n)
{
        std::uint64_t prev = Counter::_value.load();
        while(prev > n && !Counter::_value.compare_exchange_weak(prev,n)){};
}

MinCounter::MinCounter()
{
        std::cout << "Mincounter ctor" << std::endl;
        Counter::_defaultValue = -1;
        Counter::_value.store(Counter::_defaultValue);
        std::cout << "Created counter. Type=Min Size=" << sizeof(*this) << std::endl;
}

