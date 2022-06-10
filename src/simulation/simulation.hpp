#pragma once

#include "configuration.hpp"
#include "settings.hpp"
#include "terrain.hpp"

#include "numeric/vector/operators.hpp"
#include "numeric/vector/trigonometry.hpp"
#include "numeric/constants.hpp"
#include "numeric/modulo.hpp"
#include "numeric/numeric.hpp"
#include "numeric/radian.hpp"
#include "numeric/random.hpp"

using namespace numeric;
using namespace radian;

namespace simulation {

struct Trip {
    std::size_t source, destination;
};

auto RandomAngle() -> float {
    return Random::Real(-pi<float>, pi<float>);
}

auto RandomDirection() -> Vector {
    return Rotated({1, 0}, RandomAngle());
}

auto RandomTrip(std::size_t count) -> Trip {
    auto source = Random::Integer(0u, count - 1u);
    auto destination = Random::Integer(0u, count - 2u);
    destination += destination >= source;
    return {source, destination};
}

class Simulation {

public:

    Simulation(const Terrain& t, const Configuration& c, const Settings& s)
        : terrain{t}
        , configuration{c}
        , settings{s}

        , referenceDirection{1, 0}
    {
        InitializeAgents();
        InitializeFields();
    }

    auto InitializeAgents() -> void {
        directions.reset(new float[configuration.agentCapacity]);
        positions.reset(new Vector[configuration.agentCapacity]);
        trips.reset(new Trip[configuration.agentCapacity]);

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            directions[k] = settings.emissionDirection
                + RandomAngle() * settings.emissionRange;
            trips[k] = RandomTrip(configuration.locations.size());
        }

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            positions[k] = configuration.locations[trips[k].source];
        }
    }

    auto InitializeFields() -> void {
        for(auto i = 0u; i < configuration.locations.size(); ++i)
            fields.emplace_back(new float[Resolution(terrain)]);

        for(auto k = 0u; k < configuration.locations.size(); ++k)
        for(auto i = 0u; i < Resolution(terrain); ++i) {
            fields[k][i] = RandomAngle();
        }
    }

    auto Tick() -> void {
        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            positions[k] += Rotated(referenceDirection, directions[k]);
        }

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            auto practicability = TerrainAt(positions[k]);

            positions[k] -= (1.f - practicability) * Rotated(referenceDirection, directions[k]);
            directions[k] += (1.f - practicability) * RandomAngle() * settings.collisionRedirectionRange;
        }

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            auto i = IndexAt(positions[k]);
            const auto& destination = fields[trips[k].destination];

            auto angle = SignedAngle(destination[i], directions[k] + pi<float>);
            directions[k] += angle * settings.destinationReadRate;
        }

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            auto i = IndexAt(positions[k]);
            auto& source = fields[trips[k].source];

            auto angle = SignedAngle(source[i], directions[k]);
            directions[k] += angle * settings.sourceReadRate;
        }

        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            auto i = IndexAt(positions[k]);
            auto& source = fields[trips[k].source];

            auto angle = SignedAngle(directions[k], source[i]);
            source[i] += angle * settings.sourceWriteRate;
        }
                
        for(auto k = 0u; k < configuration.agentCapacity; ++k) {
            const auto& destination = configuration.locations[trips[k].destination];

            if(Distance(positions[k], destination) < settings.locationRadius) {
                std::swap(trips[k].source, trips[k].destination);
                directions[k] = RandomAngle();
                positions[k] = destination;
            }
        }
    }

public:

    auto IndexAt(const Vector& position) const -> std::size_t {
        auto i = static_cast<std::size_t>(position.x);
        auto j = static_cast<std::size_t>(position.y);
        return terrain.IndexAt(i, j);
    }

    auto TerrainAt(const Vector& position) const -> float {
        return terrain.At(IndexAt(position));
    }

public:

    Terrain terrain;
    const Configuration configuration;
    Settings settings;

    std::unique_ptr<float[]> directions;
    std::unique_ptr<Vector[]> positions;
    std::unique_ptr<Trip[]> trips;

    std::vector<std::unique_ptr<float[]>> fields;

    Vector referenceDirection;
};

} // namespace simulation
