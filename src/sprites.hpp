#pragma once

#include <SFML/Graphics.hpp>

auto LocationSprite(float radius) -> sf::CircleShape  {
    auto sprite = sf::CircleShape(radius);
    sprite.setFillColor(sf::Color::Blue);
    sprite.setOrigin({radius, radius});
    return sprite;
}
