#pragma once

class MaxCounter final : public Counter{
    public:
    void set(std::uint64_t n) override;
    MaxCounter();
    ~MaxCounter();
};
