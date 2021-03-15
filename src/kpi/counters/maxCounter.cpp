#include "counters.hpp"

void MaxCounter::set(std::uint64_t n)
{
        std::uint64_t prev = Counter::_value.load();
        while(prev < n && !Counter::_value.compare_exchange_weak(prev,n)){};
}

MaxCounter::MaxCounter()
{
        std::cout << "Maxcounter ctor" << std::endl;
        Counter::_defaultValue = -1;
        Counter::_value.store(Counter::_defaultValue);
        std::cout << "Created counter. Type=Max Size=" << sizeof(*this) << std::endl;
}
