#pragma once

#include "simulation/terrain.hpp"

#include <SFML/Graphics/Image.hpp>

auto NormalizedGray(const sf::Color& c) -> float {
    auto r = static_cast<float>(c.r);
    auto g = static_cast<float>(c.g);
    auto b = static_cast<float>(c.b);
    return (r + g + b) / (3.f * 255.f);
}

auto ToTerrain(const sf::Image& toConvert) -> simulation::Terrain {
    auto size = toConvert.getSize();
    auto data = new float[size.x * size.y];
    for(auto j = 0u; j < size.y; ++j) {
        auto row = j * size.x;
        for(auto i = 0u; i < size.y; ++i)
            data[row + i] = NormalizedGray(toConvert.getPixel(i, j));
    }
    return {size.x, size.y, data};
}
