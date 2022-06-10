cmake_minimum_required(VERSION 3.7)

project(cartography)

add_executable(main)

target_link_directories(main
    PUBLIC
        ${CMAKE_SOURCE_DIR}/lib
)

target_link_libraries(main
    sfml-graphics
    sfml-window
    sfml-system
)

target_include_directories(main
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_sources(main
    PUBLIC
        ${CMAKE_SOURCE_DIR}/src/main.cpp
)
