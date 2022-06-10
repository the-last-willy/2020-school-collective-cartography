auto CrossProduct(const Vector& lhs, const Vector& rhs) -> float {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

auto Difference(const Vector& lhs, const Vector& rhs) -> Vector {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

auto Distance(const Vector& lhs, const Vector& rhs) -> float {
    return Norm(Difference(lhs, rhs));
}

auto DotProduct(const Vector& lhs, const Vector& rhs) -> float {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

auto Norm(const Vector& v) -> float {
    return std::sqrt(SquaredNorm(v));
}

auto Normalize(Vector& v) -> Vector& {
    return v = Normalized(v);
}

auto Normalized(const Vector& v) -> Vector {
    return Quotient(v, Norm(v));
}

auto Opposite(const Vector& v) -> Vector {
    return {-v.x, -v.y};
}

auto Product(float lhs, const Vector& rhs) -> Vector {
    return {lhs * rhs.x, lhs * rhs.y};
}

auto Product(const Vector& lhs, float rhs) -> Vector {
    return {lhs.x * rhs, lhs.y * rhs};
}

auto Quotient(const Vector& lhs, float rhs) -> Vector {
    return {lhs.x / rhs, lhs.y / rhs};
}

auto SquaredNorm(const Vector& v) -> float {
    return DotProduct(v, v);
}

auto Sum(const Vector& lhs, const Vector& rhs) -> Vector {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}
