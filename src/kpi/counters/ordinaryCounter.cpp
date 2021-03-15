#include "counters.hpp"

void OrdinaryCounter::set(std::uint64_t n)
{
        Counter::_value.store(n);
}

OrdinaryCounter::OrdinaryCounter()
{
        std::cout << "OrdinaryCounter ctor" << std::endl;
        Counter::_defaultValue = 0;
        Counter::_value.store(Counter::_defaultValue);
        std::cout << "Created counter. Type=Ordinary Size=" << sizeof(*this) << std::endl;
}

