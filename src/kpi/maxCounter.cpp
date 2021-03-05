#include "counters.hpp"

template <class T>
void MaxCounter<T>::set(T n)
{
        T prev = Counter<T>::_value.load();
        while(prev < n && !Counter<T>::_value.compare_exchange_weak(prev,n)){};
}

template <class T>
MaxCounter<T>::MaxCounter()
{
        std::cout << "Maxcounter ctor" << std::endl;
        Counter<T>::_defaultValue = -1;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
}

