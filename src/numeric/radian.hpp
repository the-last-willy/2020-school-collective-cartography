#pragma once

#include "constants.hpp"
#include "modulo.hpp"

namespace numeric {
namespace radian {

template<typename Numeric>
auto SignedAngle(Numeric lhs, Numeric rhs) -> Numeric;

template<typename Numeric>
auto ToDegree(Numeric n) -> Numeric;

#include "radian.inl"

} // namespace radians
} // namespace numeric


