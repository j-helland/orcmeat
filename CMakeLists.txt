cmake_minimum_required(VERSION 3.14...3.19)

project(
    OrcMeat 
    VERSION 0.0 
    DESCRIPTION "How tf do I use CMake?"
    LANGUAGES CXX C)

# CMake 3.11+ Downloads stuff during configure step
include(FetchContent)

# GLFW for windows, contexts, input, events, etc.
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.3
)

# JSON serialization library
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.9.1)

# Add nlohmann_json::nlohmann_sjon
FetchContent_MakeAvailable(glfw json)

# Library code lives here.
add_subdirectory(src)

# Main game driver lives here.
add_subdirectory(game)