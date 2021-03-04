#include <iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                        
#include <atomic>
#include <stdint.h>

template <class T> class Counter;
template <class T> class MinCounter;
template <class T> class MaxCounter;
template <class T> class CumulativeCounter;
template <class T> class OrdinaryCounter;


template <class T>
class Counter{
    protected:
        T _defaultValue;
        std::atomic<T> _value;
    public:
        T dump(){
            return std::atomic_exchange(&_value, _defaultValue);
        }

        virtual void set(T n) = 0;

        T get(){
            return _value.load();
        }
};

template <class T>
class MinCounter final : public Counter<T> {
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


int main () {
    MinCounter<uint64_t>max();

    std::cout << "Max.get() = " << max.get() << std::endl;
    max.set(15);
    std::cout << "Set 15" << std::endl;

    max.set(25);
    std::cout << "Set 25" << std::endl;

    std::cout << "Max.get() = " << max.get() << std::endl;
    return 0;
}
