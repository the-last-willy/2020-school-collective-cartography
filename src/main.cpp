#include "application.hpp"
#include "scenario.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        if(argc < 2)
            throw std::runtime_error{"invalid number of arguments"};

        auto scenarios = PredefinedScenarios();

        auto scenario = scenarios.find(argv[1]);
        if(scenario == scenarios.end())
            throw std::runtime_error{std::string{"unknown scenario "} + argv[1]};

        Application{scenario->second};
    } catch(std::exception e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << "UNKNOWN EXCEPTION" << std::endl;
    }

    return 0;
}
