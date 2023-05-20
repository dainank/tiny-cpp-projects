#include <iostream>
#include <functional>

template<typename T, typename U>
auto simple_plus(T lhs, U rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

auto main() -> int {
    std::cout << std::plus<int>{}(1, 1.23) << "\n";
    std::cout << std::plus<>{}(1, 1.23) << "\n";

    // using our impl.
    std::cout << simple_plus(1, 1.23) << "\n";
}
