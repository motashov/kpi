#include <iostream>
#include <atomic>
#include <stdint.h>

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



template <class T>
class MinCounter final : public Counter<T> {
    public:
    void set(T n) override{
        T prev = Counter<T>::_value.load();
        while(prev > n && !Counter<T>::_value.compare_exchange_weak(prev,n)){};
    }
    MinCounter() {
        std::cout << "Mincounter ctor" << std::endl;
        Counter<T>::_defaultValue = -1;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
    }
};

template <class T>
class MaxCounter final : public Counter<T> {
    public:
    void set(T n) override{
        T prev = Counter<T>::_value.load();
        while(prev < n && !Counter<T>::_value.compare_exchange_weak(prev,n)){};
    }
    MaxCounter(){
        std::cout << "MaxCounter ctor" << std::endl;
        Counter<T>::_defaultValue = 0;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
    }
};

template <class T>
class CumulativeCounter final : public Counter<T> {
    public:
    void set(T n) override{
        Counter<T>::_value+=n;
    }
    CumulativeCounter(){
        std::cout << "CumulativeCounter ctor" << std::endl;
        Counter<T>::_defaultValue = 0;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
    }
};

template <class T>
class OrdinaryCounter final : public Counter<T> {
    public:
    void set(T n) override{
        Counter<T>::_value.store(n);
    }
    OrdinaryCounter(){
        std::cout << "OrdinaryCounter ctor" << std::endl;
        Counter<T>::_defaultValue = 0;
        Counter<T>::_value.store(Counter<T>::_defaultValue);
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
    }
};
