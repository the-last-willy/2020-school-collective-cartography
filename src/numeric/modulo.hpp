#pragma once

#include <cmath>

namespace numeric {

template<typename Integer>
auto PositiveModulo(Integer lhs, Integer rhs)
-> typename std::enable_if<std::is_integral<Integer>::value, Integer>::type;

template<typename Floating>
auto PositiveModulo(Floating lhs, Floating rhs)
-> typename std::enable_if<std::is_floating_point<Floating>::value, Floating>::type;

template<typename Integer>
auto SignedModulo(Integer lhs, Integer rhs)
-> typename std::enable_if<std::is_integral<Integer>::value, Integer>::type;

template<typename Floating>
auto SignedModulo(Floating lhs, Floating rhs)
-> typename std::enable_if<std::is_floating_point<Floating>::value, Floating>::type;

#include "modulo.inl"

} // namespace numeric
