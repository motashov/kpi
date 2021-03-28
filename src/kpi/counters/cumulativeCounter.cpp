#include "counters.hpp"

void CumulativeCounter::set(std::uint64_t n)
{
        Counter::_value+=n;
}

CumulativeCounter::CumulativeCounter()
{
        std::cout << "CumulativeCounter ctor" << std::endl;
        Counter::_defaultValue = 0;
        Counter::_value.store(Counter::_defaultValue);
        std::cout << "Created counter. Type=Cumulative Size=" << sizeof(*this) << std::endl;
}

CumulativeCounter::~CumulativeCounter()
{
        std::cout << "CumulativeCounter dtor" << std::endl;
}

