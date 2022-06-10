#pragma once

#include "numeric/vector/vector.hpp"

#include <memory>
#include <vector>

namespace simulation {

struct Configuration {
    std::size_t agentCapacity;
    std::vector<numeric::Vector> locations;
};

} // namespace simulation
