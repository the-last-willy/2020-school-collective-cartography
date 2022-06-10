#pragma once

struct Settings {
    bool updating;

    unsigned updatePerFrame;

    std::size_t selectedLocation;
};

auto DefaultSettings() -> Settings {
    Settings s;
    s.selectedLocation = 100;
    s.updatePerFrame = 1;
    s.updating = false;
    return s;
}
