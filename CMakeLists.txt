cmake_minimum_required(VERSION 3.12)
project(MazeGeneratorWalls VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries(stdc++fs)

enable_testing()
include(CTest)

add_subdirectory(tests)
add_subdirectory(src)
