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
        T dump();
        virtual void set(T n) = 0;
        T get();
};

