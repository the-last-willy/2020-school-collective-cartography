#pragma once

#include <memory>

namespace simulation {

class Terrain {
public:

    Terrain(std::size_t width, std::size_t height, float data[])
        : width{width}
        , height{height}
        , data{data}
    {}

    auto At(std::size_t index) const -> float {
        return data[index];
    }

    auto IndexAt(std::size_t i, std::size_t j) const {
        return j * width + i;
    }

    auto Width() const {
        return width;
    }

    auto Height() const {
        return height;
    }

private:
    std::size_t width, height;
    std::shared_ptr<float[]> data;
};

auto Resolution(const Terrain& t) -> std::size_t {
    return t.Width() * t.Height();
}

} // namespace simulation
