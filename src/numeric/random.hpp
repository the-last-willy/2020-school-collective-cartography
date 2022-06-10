#pragma once

#include <random>

namespace numeric {

class Random {
public:

    template<typename Floating> static
    auto Floating(Floating lowerBound, Floating upperBound) -> Floating {
        auto distribution = std::uniform_real_distribution<Floating>(
            lowerBound, upperBound
        );
        return distribution(generator);
    }

    template<typename Integer> static
    auto Integer(Integer lowerBound, Integer upperBound) -> Integer {
        auto distribution = std::uniform_int_distribution<Integer>(
            lowerBound, upperBound
        );
        return distribution(generator);
    }

    template<typename Real> static
    auto Real(Real lowerBound, Real upperBound) -> Real {
        auto distribution = std::uniform_real_distribution<Real>(
            lowerBound, upperBound
        );
        return distribution(generator);
    }

private:

    static
    auto Seed() -> unsigned;

    static
    std::mt19937 generator;
};

std::mt19937 Random::generator(Random::Seed());

auto Random::Seed() -> unsigned {
    std::random_device entropySource{};
    return entropySource();
}

#include "random.inl"

} // namespace numeric
