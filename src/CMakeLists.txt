# File glob requires CMake 3.12 or later.
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${OrcMeat_SOURCE_DIR}/include/*.hpp")

add_library(game_library lib.cpp ${HEADER_LIST})

# This must be public so that the game can include our library.
target_include_directories(game_library PUBLIC ../include)

target_compile_features(game_library PUBLIC cxx_std_17)