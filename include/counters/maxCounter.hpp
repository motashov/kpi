template <class T> class Counter;
template <class T>
class MaxCounter final : public Counter<T> {
    public:
    void set(T n) override;
    MaxCounter();
};

