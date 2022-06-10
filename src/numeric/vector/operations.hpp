#pragma once

#include "vector.hpp"

#include <cmath>

namespace numeric {

auto CrossProduct(const Vector& lhs, const Vector& rhs) -> float;

auto Difference(const Vector& lhs, const Vector& rhs) -> Vector;

auto Distance(const Vector& lhs, const Vector& rhs) -> float;

auto DotProduct(const Vector& lhs, const Vector& rhs) -> float;

auto Norm(const Vector& v) -> float;

auto Normalize(Vector& v) -> Vector&;

auto Normalized(const Vector& v) -> Vector;

auto Opposite(const Vector& v) -> Vector;

auto Product(float lhs, const Vector& rhs) -> Vector;

auto Product(const Vector& lhs, float rhs) -> Vector;

auto Quotient(const Vector& lhs, float rhs) -> Vector;

auto SquaredNorm(const Vector& v) -> float;

auto Sum(const Vector& lhs, const Vector& rhs) -> Vector;

#include "operations.inl"

} // namespace numeric
