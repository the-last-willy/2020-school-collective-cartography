auto operator -(const Vector& v) -> Vector {
    return Opposite(v);
}

auto operator *=(Vector& lhs, float rhs) -> Vector& {
    return lhs = Product(lhs, rhs);
}

auto operator *(float lhs, const Vector& rhs) -> Vector {
    return Product(lhs, rhs);
}

auto operator *(Vector lhs, float rhs) -> Vector {
    return lhs *= rhs;
}

auto operator /=(Vector& lhs, float rhs) -> Vector& {
    return lhs = Quotient(lhs, rhs);
}

auto operator /(Vector lhs, float rhs) -> Vector {
    return lhs /= rhs;
}

auto operator +=(Vector& lhs, const Vector& rhs) -> Vector& {
    return lhs = Sum(lhs, rhs);
}

auto operator +(Vector lhs, const Vector& rhs) -> Vector {
    return lhs += rhs;
}

auto operator -=(Vector& lhs, const Vector& rhs) -> Vector& {
    return lhs = Difference(lhs, rhs);
}

auto operator -(Vector lhs, const Vector& rhs) -> Vector {
    return lhs -= rhs;
}
