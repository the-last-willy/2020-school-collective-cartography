#pragma once

#include <SFML/Graphics/Image.hpp>

#include <stdexcept>
#include <string>

auto LoadImage(const std::string& filePath) -> sf::Image {
    auto image = sf::Image{};
    auto success = image.loadFromFile(filePath);
    if(!success)
        throw std::runtime_error{"failed to load " + filePath};
    return image;
}
