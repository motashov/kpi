#pragma once

class MinCounter final : public Counter {
    public:
    void set(std::uint64_t n) override;
    MinCounter();
    ~MinCounter();
};

