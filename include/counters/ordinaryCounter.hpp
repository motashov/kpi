template <class T> class Counter;

template <class T>
class OrdinaryCounter final : public Counter<T> {
    public:
    void set(T n) override;
    OrdinaryCounter();
};

