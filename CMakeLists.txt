cmake_minimum_required(VERSION 3.25)
project(marching_squares)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(marching_squares main.cpp Application.cpp Application.h MarchingSquares.cpp MarchingSquares.h PerlinNoise.cpp PerlinNoise.h Bounds.cpp Bounds.h)
target_link_libraries(marching_squares ${SDL2_LIBRARIES})