cmake_minimum_required(VERSION 3.10)
project(chess-engine)

set(SOURCES
	src/main.cpp
	src/core/board.cpp
)

add_subdirectory(third_party/spdlog)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED TRUE
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE spdlog
)

target_include_directories(${PROJECT_NAME}
	PRIVATE src
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE $<$<CONFIG:Debug>:_DEBUG>
)