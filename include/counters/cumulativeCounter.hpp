#pragma once

class CumulativeCounter final : public Counter {
    public:
    void set(std::uint64_t n) override;
    CumulativeCounter();
};
