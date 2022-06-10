auto Rotate(Vector& v, float radians) -> Vector& {
    return v = Rotated(v, radians);
}

auto Rotated(const Vector& v, float radians) -> Vector {
    auto c = std::cos(radians), s = std::sin(radians);
    return {c * v.x - s * v.y, s * v.x + c * v.y};
}
