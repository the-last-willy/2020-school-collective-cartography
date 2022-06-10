#pragma once

#include "image.hpp"
#include "load.hpp"
#include "settings.hpp"
#include "sprites.hpp"
#include "scenario.hpp"

#include "simulation/simulation.hpp"

#include <algorithm>

#include <SFML/Graphics.hpp>

class Application {
public:

    Application(const Scenario& s)
        : terrainImage{LoadImage(s.terrainFilePath)}

        , settings{DefaultSettings()}
        
        , window(
            sf::VideoMode(terrainImage.getSize().x, terrainImage.getSize().y),
            "LIFPROJET: Collective Cartography"
        )

        , simulation(ToTerrain(terrainImage), s.configuration, s.settings)

        , locationSprite{LocationSprite(simulation.settings.locationRadius)}

        , colors{sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Magenta}
    {
        Initialize();
        Run();
    }

private:

    auto Initialize() -> void {
        terrainImage.createMaskFromColor(sf::Color::White);

        fieldImage.create(terrainImage.getSize().x, terrainImage.getSize().y);
        
        fieldTexture.create(terrainImage.getSize().x, terrainImage.getSize().y);
        terrainTexture.loadFromImage(terrainImage);

        fieldSprite.setTexture(fieldTexture);
        terrainSprite.setTexture(terrainTexture);
    }
    
    auto Run() -> void {
        auto clock = sf::Clock{};
        auto timePerFrame = sf::seconds(1.f / 60.f);
        auto timeSinceFrame = sf::Time::Zero;

        while(window.isOpen()) {
            timeSinceFrame += clock.restart();

            HandleEvents();

            while(timeSinceFrame >= timePerFrame) {
                // skip pending frames
                timeSinceFrame %= timePerFrame;

                if(settings.updating)
                    for(auto k = 0u; k < settings.updatePerFrame; ++k)
                        simulation.Tick();

                Render();
            }
        }
    }

    auto HandleEvents() -> void {
        for(sf::Event e; window.pollEvent(e);) {
            switch(e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    HandleEvent(e.key);
                    break;
                case sf::Event::Resized:
                    HandleResized(e.size);
                    break;
            }
            if(e.type == sf::Event::Closed)
                window.close();
        }
    }

    auto HandleEvent(const sf::Event::KeyEvent& e) -> void {
        switch(e.code) {
            case sf::Keyboard::A:
                colors = {sf::Color::Red, sf::Color::White, sf::Color::White, sf::Color::White};
                break;
            case sf::Keyboard::Add:
                settings.updatePerFrame += 1;
                break;
            case sf::Keyboard::Z:
                colors = {sf::Color::White, sf::Color::Blue, sf::Color::White, sf::Color::White};
                break;
            case sf::Keyboard::E:
                colors = {sf::Color::White, sf::Color::White, sf::Color::Green, sf::Color::White};
                break;
            case sf::Keyboard::R:
                colors = {sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::Magenta};
                break;
            case sf::Keyboard::T:
                colors = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Magenta};
                break;
            case sf::Keyboard::Numpad1:
                settings.selectedLocation = 0;
                break;
            case sf::Keyboard::Numpad2:
                settings.selectedLocation = 1;
                break;
            case sf::Keyboard::Numpad3:
                settings.selectedLocation = 2;
                break;
            case sf::Keyboard::Numpad4:
                settings.selectedLocation = 3;
                break;
            case sf::Keyboard::Numpad5:
                settings.selectedLocation = 4;
                break;
            case sf::Keyboard::Space:
                settings.updating = !settings.updating;
                break;
            case sf::Keyboard::Subtract:
                if(settings.updatePerFrame != 0)
                    settings.updatePerFrame -= 1;
                break;
        }
    }

    auto HandleResized(const sf::Event::SizeEvent& e) -> void {
        auto side = std::max(e.width, e.height);
        window.setSize({side, side});
    }

    auto Render() -> void {
        ClearField();
        RenderField();

        RenderAgents();

        fieldTexture.update(fieldImage);

        window.clear();

        window.draw(fieldSprite);
        window.draw(terrainSprite);

        for(auto i = 0u; i < simulation.configuration.locations.size(); ++i) {
            locationSprite.setFillColor(colors[i]);
            locationSprite.setPosition(
                simulation.configuration.locations[i].x,
                simulation.configuration.locations[i].y
            );
            window.draw(locationSprite);
        }            

        window.display();
    }

    auto ClearField() -> void {
        for(auto j = std::size_t{0}; j < simulation.terrain.Height(); ++j)
        for(auto i = std::size_t{0}; i < simulation.terrain.Width(); ++i)
            fieldImage.setPixel(i, j, sf::Color::White);
    }

    auto RenderField() -> void {
        if(settings.selectedLocation < simulation.configuration.locations.size()) {
            const auto& field = simulation.fields[settings.selectedLocation];
            for(auto j = std::size_t{0}; j < simulation.terrain.Height(); ++j)
            for(auto i = std::size_t{0}; i < simulation.terrain.Width(); ++i) {
                auto direction = field[simulation.terrain.IndexAt(i, j)];
                auto h = std::cos(direction) / 2 + 0.5, v = std::sin(direction) / 2 + 0.5;
                auto r = static_cast<sf::Uint8>(255.f * h);
                auto g = static_cast<sf::Uint8>(255.f * v);
                fieldImage.setPixel(i, j, {r, g, 128u, 255u});
            }
        }
    }

    auto RenderAgents() -> void {
        for(auto k = 0u; k < simulation.configuration.agentCapacity; ++k) {
            auto source = simulation.trips[k].source;
            auto position = simulation.positions[k];
            auto i = static_cast<std::size_t>(position.x);
            auto j = static_cast<std::size_t>(position.y);
            fieldImage.setPixel(i, j, colors[source]);
        }
    }

private:

    sf::Image terrainImage;

    Settings settings;

    sf::RenderWindow window;

    simulation::Simulation simulation;

    sf::Image fieldImage;

    sf::Texture fieldTexture;
    sf::Texture terrainTexture;

    sf::Sprite fieldSprite;
    sf::CircleShape locationSprite;
    sf::Sprite terrainSprite;

    std::vector<sf::Color> colors;
};
