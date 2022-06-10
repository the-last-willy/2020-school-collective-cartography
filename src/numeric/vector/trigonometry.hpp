#pragma once

#include "vector.hpp"

#include "operations.hpp"

#include <cmath>

namespace numeric {

auto Rotate(Vector&, float radians) -> Vector&;

auto Rotated(const Vector& v, float radians) -> Vector;

#include "trigonometry.inl"

} // namespace numeric
