
template <class T> class Counter;
template <class T>
class MinCounter final : public Counter<T> {
    public:
    void set(T n) override;
    MinCounter();
};

