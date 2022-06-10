template<typename Integer>
auto PositiveModulo(Integer lhs, Integer rhs)
-> typename std::enable_if<std::is_integral<Integer>::value, Integer>::type {
    return (lhs % rhs + rhs) % rhs;
}

template<typename Floating>
auto PositiveModulo(Floating lhs, Floating rhs)
-> typename std::enable_if<std::is_floating_point<Floating>::value, Floating>::type {
    return lhs - std::floor(lhs / rhs) * rhs;
}

template<typename Integer>
auto SignedModulo(Integer lhs, Integer rhs)
-> typename std::enable_if<std::is_integral<Integer>::value, Integer>::type {
    return lhs % rhs;
}

template<typename Floating>
auto SignedModulo(Floating lhs, Floating rhs)
-> typename std::enable_if<std::is_floating_point<Floating>::value, Floating>::type {
    return fmod(lhs, rhs);
}
