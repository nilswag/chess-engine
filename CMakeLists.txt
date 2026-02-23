cmake_minimum_required(VERSION 3.10)
project(chess-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(chess-engine ${SOURCES})

target_include_directories(chess-engine
    PRIVATE src/
)