template<typename Numeric>
auto SignedAngle(Numeric lhs, Numeric rhs) -> Numeric {
    constexpr auto whole = pi<Numeric> * Numeric{2}, half = pi<Numeric>;
    return PositiveModulo(lhs - rhs + half, whole) - half;
}

template<typename Numeric>
auto ToDegree(Numeric n) -> Numeric {
    return n / pi<float> * Numeric{180};
}
