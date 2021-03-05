template <class T> class Counter;

template <class T>
class CumulativeCounter final : public Counter<T> {
    public:
    void set(T n) override;
    CumulativeCounter();
};
