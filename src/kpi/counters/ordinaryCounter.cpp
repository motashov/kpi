#include "counters.hpp"

template <class T>
void OrdinaryCounter<T>::set(T n)
{
        Counter<T>::_value.store(n);
}

template <class T>
MaxCounter<T>::MaxCounter()
{
        std::cout << "OrdinaryCounter ctor" << std::endl;
        Counter<T>::_defaultValue = 0;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
}
