#include "counters.hpp"

template <class T>
T Counter<T>::dump()
{
    return std::atomic_exchange(&_value, _defaultValue);
}

template <class T>
T Counter<T>::get(){
    return _value.load();
}

