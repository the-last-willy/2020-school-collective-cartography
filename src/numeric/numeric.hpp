#pragma once

#include <cmath>

template<typename Numeric>
auto Clamp(Numeric lb, Numeric x, Numeric ub) -> Numeric {
    return std::max(lb, std::min(x, ub));
}

template<typename Numeric>
auto Sign(Numeric n) -> Numeric {
    auto less = (n < 0) ? Numeric{1} : Numeric{0}
    auto greater = (n > 0) ? Numeric{1} : Numeric{0};
    return greater - less;
}
