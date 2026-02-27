cmake_minimum_required(VERSION 3.10)
project(little-chess-engine)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE include/
)

if("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
    target_compile_options(${PROJECT_NAME}
        PRIVATE -fmacro-prefix-map=${PROJECT_SOURCE_DIR}/=
    )
endif()