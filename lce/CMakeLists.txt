cmake_minimum_required(VERSION 3.10)
project(lce)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCES src/*.c)
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC include/
)