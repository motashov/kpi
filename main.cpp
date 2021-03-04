#include <iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                        
#include <atomic>
#include <stdint.h>

enum class type{
    ORDINARY,
    MIN,
    MAX,
    CUMULATIVE
};

template <class T>
struct Counter{
    private:
    T _defaultValue;
    std::atomic<T> _value;
    type _type;
    public:
    Counter(type t){ 
        switch (t){
            case type::MIN : { 
                _defaultValue = -1; 
                break;
            }
            default:{
                _defaultValue = 0;
                break;
            }
        }
        _value.store(_defaultValue);
        _type = t;
        std::cout << "Created counter. Size=" << sizeof(*this) << std::endl;
    }   

    T dump(){
        return std::atomic_exchange(&_value, _defaultValue);
    }   

    void set(T n){ 
        switch (_type){
            case type::MIN : { 
                T prev = _value.load();
                while(prev > n && !_value.compare_exchange_weak(prev,n)){};
                break;
            }
            case type::MAX : { 
                T prev = _value.load();
                while(prev < n && !_value.compare_exchange_weak(prev,n)){};
                break;
            }
            case type::ORDINARY : { 
                _value.store(n);
                break;
            }
            case type::CUMULATIVE : { 
                _value+=n;
                break;
            }
        }
    }   
    T get(){
        return _value.load();
    }   

};


int main () {
    Counter<uint64_t>max(type::MAX);

    std::cout << "Max.get() = " << max.get() << std::endl;
    max.set(15);
    std::cout << "Set 15" << std::endl;

    max.set(25);
    std::cout << "Set 25" << std::endl;

    std::cout << "Max.get() = " << max.get() << std::endl;
    return 0;
}
