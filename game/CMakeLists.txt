add_executable(game orcmeat.cpp)
target_compile_features(game PRIVATE cxx_std_17)

# OpenGL
find_package(OpenGL REQUIRED)                      # where are you
include_directories(${OPENGL_INCLUDE_DIRS})        # where are ur includes

target_link_libraries(game PRIVATE game_library nlohmann_json::nlohmann_json glfw ${OPENGL_LIBRARIES})