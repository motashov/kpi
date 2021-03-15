#pragma once

class OrdinaryCounter final : public Counter {
    public:
    void set(std::uint64_t n) override;
    OrdinaryCounter();
};

