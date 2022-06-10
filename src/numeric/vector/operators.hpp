#pragma once

#include "vector.hpp"

#include "operations.hpp"

namespace numeric {

auto operator -(const Vector& v) -> Vector;

auto operator *=(Vector& lhs, float rhs) -> Vector&;

auto operator *(float lhs, const Vector& rhs) -> Vector;

auto operator *(Vector lhs, float rhs) -> Vector;

auto operator /=(Vector& lhs, float rhs) -> Vector&;

auto operator /(Vector lhs, float rhs) -> Vector;

auto operator +=(Vector& lhs, const Vector& rhs) -> Vector&;

auto operator +(Vector lhs, const Vector& rhs) -> Vector;

auto operator -=(Vector& lhs, const Vector& rhs) -> Vector&;

auto operator -(Vector lhs, const Vector& rhs) -> Vector;

#include "operators.inl"

} // namespace numeric
