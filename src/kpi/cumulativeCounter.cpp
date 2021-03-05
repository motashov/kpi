#include "counters.hpp"

template <class T>
void CumulativeCounter<T>::set(T n)
{
        Counter<T>::_value+=n;
}

template <class T>
MaxCounter<T>::MaxCounter()
{
        std::cout << "CumulativeCounter ctor" << std::endl;
        Counter<T>::_defaultValue = 0;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
}

