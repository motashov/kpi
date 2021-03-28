#include "counters.hpp"

std::uint64_t Counter::dump()
{
    return std::atomic_exchange(&_value, _defaultValue);
}

std::uint64_t Counter::get(){
    return _value.load();
}

Counter::Counter()
{
    std::cout << "Counter ctor" << std::endl;
}

Counter::~Counter()
{
    std::cout << "Counter dtor" << std::endl;
}
