cmake_minimum_required(VERSION 3.10)
project(chess-engine C)

set(SOURCES
	src/main.c
	src/core/board.c
)

include(CTest)

add_subdirectory(third_party/nwbase)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	C_STANDARD 17
	C_STANDARD_REQUIRED TRUE
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE nwbase
)

target_include_directories(${PROJECT_NAME}
	PRIVATE src
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE $<$<CONFIG:Debug>:_DEBUG>
)