#pragma once

#include "simulation/configuration.hpp"
#include "simulation/settings.hpp"

#include <map>
#include <string>

struct Scenario {
    simulation::Configuration configuration;
    simulation::Settings settings;
    std::string terrainFilePath;
};

auto Emission1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 1'000;
    s.configuration.locations = {{200, 200}, {380, 20}};
    s.settings = simulation::DefaultSettings();
    s.settings.collisionRedirectionRange = 0.f;
    s.terrainFilePath = "assets/single_400.png";
    return s;
}

auto Collision1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 10'000;
    s.configuration.locations = {{20, 320}, {380, 20}};
    s.settings = simulation::DefaultSettings();
    s.settings.emissionDirection = 0.45f;
    s.settings.emissionRange = 0.f;
    s.terrainFilePath = "assets/single_400.png";
    return s;
}

auto Collision2() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 10'000;
    s.configuration.locations = {{380, 20}, {20, 380}};
    s.settings = simulation::DefaultSettings();
    s.terrainFilePath = "assets/s_shape_400.png";
    return s;
}

auto Eloignement1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 20'000;
    s.configuration.locations = {{200, 200}, {380, 20}};
    s.settings = simulation::DefaultSettings();
    s.settings.sourceReadRate = 1.f / 2;
    s.settings.sourceWriteRate = 1.f / 2;
    s.terrainFilePath = "assets/single_400.png";
    return s;
}

auto Eloignement2() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 10'000;
    s.configuration.locations = {{380, 20}, {20, 380}};
    s.settings = simulation::DefaultSettings();
    s.settings.sourceReadRate = 1.f / 2;
    s.settings.sourceWriteRate = 1.f / 2;
    s.terrainFilePath = "assets/s_shape_400.png";
    return s;
}

auto Rapprochement1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 10'000;
    s.configuration.locations = {{100, 200}, {300, 200}};
    s.settings = simulation::DefaultSettings();
    s.settings.destinationReadRate = 1.f / 8;
    s.settings.sourceWriteRate = 1.f;
    s.terrainFilePath = "assets/empty_400.png";
    return s;
}

auto Trajet1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 10'000;
    s.configuration.locations = {{50, 200}, {350, 200}};
    s.settings = simulation::DefaultSettings();
    s.settings.destinationReadRate = 1.f / 8;
    s.settings.locationRadius = 20.f;
    s.settings.sourceReadRate = 1.f / 4;
    s.settings.sourceWriteRate = 1.f / 16;
    s.terrainFilePath = "assets/empty_400.png";
    return s;
}

auto Trajet2() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 20'000;
    s.configuration.locations = {{380, 20}, {20, 380}};
    s.settings = simulation::DefaultSettings();
    s.settings.destinationReadRate = 1.f / 8;
    s.settings.locationRadius = 10.f;
    s.settings.sourceReadRate = 1.f / 4;
    s.settings.sourceWriteRate = 1.f / 16;
    s.terrainFilePath = "assets/s_shape_400.png";
    return s;
}

auto Demonstration1() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 20'000;
    s.configuration.locations = {{20, 20}, {380, 380}};
    s.settings = simulation::DefaultSettings();
    s.settings.destinationReadRate = 1.f / 8;
    s.settings.locationRadius = 10.f;
    s.settings.sourceReadRate = 1.f / 4;
    s.settings.sourceWriteRate = 1.f / 16;
    s.terrainFilePath = "assets/labyrinth_1_400.png";
    return s;
}

auto Demonstration2() -> Scenario {
    auto s = Scenario{};
    s.configuration.agentCapacity = 20'000;
    s.configuration.locations = {{50, 50}, {350, 350}};
    s.settings = simulation::DefaultSettings();
    s.settings.destinationReadRate = 1.f / 8;
    s.settings.locationRadius = 10.f;
    s.settings.sourceReadRate = 1.f / 4;
    s.settings.sourceWriteRate = 1.f / 16;
    s.terrainFilePath = "assets/labyrinth_2_400.png";
    return s;
}

auto PredefinedScenarios() -> std::map<std::string, Scenario> {
    return {
        {"emission_1", Emission1()},
        {"collision_1", Collision1()},
        {"collision_2", Collision2()},
        {"eloignement_1", Eloignement1()},
        {"eloignement_2", Eloignement2()},
        {"rapprochement_1", Rapprochement1()},
        {"trajet_1", Trajet1()},
        {"trajet_2", Trajet2()},
        {"demonstration_1", Demonstration1()},
        {"demonstration_2", Demonstration2()}
    };
}
