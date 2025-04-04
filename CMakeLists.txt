cmake_minimum_required(VERSION 3.30)
project (exercise6)
find_package(SDL3 CONFIG REQUIRED)
add_executable(${PROJECT_NAME} WIN32)
target_sources(${PROJECT_NAME}
    PRIVATE
    Point.hpp Point.cpp
    AppState.hpp AppState.cpp
    main.cpp
)

target_link_libraries (${PROJECT_NAME}
PRIVATE
 SDL3::SDL3)
