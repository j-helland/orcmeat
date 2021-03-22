# Create game executable
add_executable(game ../glad/src/glad.c orcmeat.cpp)

# Specify C++ 17
target_compile_features(game PRIVATE cxx_std_17)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add GLAD and OpenGL include directories
include_directories(${OPENGL_INCLUDE_DIRS} ../glad/include)

# Link game lib, json, glfw, OpenGL against game target
target_link_libraries(game PRIVATE game_library nlohmann_json::nlohmann_json glfw ${OPENGL_LIBRARIES})