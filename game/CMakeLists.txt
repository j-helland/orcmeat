add_executable(game orcmeat.cpp)
target_compile_features(game PRIVATE cxx_std_17)

target_link_libraries(game PRIVATE game_library nlohmann_json::nlohmann_json)
