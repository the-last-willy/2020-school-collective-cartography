#pragma once

namespace simulation {

struct Settings {
    float collisionRedirectionRange;

    float destinationReadRate;

    float emissionDirection;

    float emissionRange;

    float locationRadius;

    float sourceReadRate;

    float sourceWriteRate;
};

auto DefaultSettings() -> Settings {
    Settings s;
    s.collisionRedirectionRange = 1.f / 2;
    s.destinationReadRate = 0.f;
    s.emissionDirection = 0.f;
    s.emissionRange = 1.f;
    s.locationRadius = 5.f;
    s.sourceReadRate = 0.f;
    s.sourceWriteRate = 1.f;
    return s;
}

} // namespace simulation
