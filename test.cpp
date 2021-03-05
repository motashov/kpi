#include "include/counters.hpp"

int main () {
    MaxCounter<uint64_t> counter;

    std::cout << "get() = " << counter.get() << std::endl;
    counter.set(15);
    std::cout << "Set 15" << std::endl;

    counter.set(25);
    std::cout << "Set 25" << std::endl;

    std::cout << "get() = " << counter.get() << std::endl;
    return 0;
}
