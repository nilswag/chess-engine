cmake_minimum_required(VERSION 3.10)
project(chess-engine LANGUAGES C)

set(SOURCES
	src/main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	C_STANDARD 23
	C_STANDARD_REQUIRED TRUE
)

target_include_directories(${PROJECT_NAME}
	PRIVATE src
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE $<$<CONFIG:Debug>:_DEBUG>
)