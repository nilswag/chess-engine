cmake_minimum_required(VERSION 3.10)
project(chess-engine)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCES src/*.c)
add_executable(chess-engine ${SOURCES})

target_include_directories(chess-engine
    PRIVATE src/
)