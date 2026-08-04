cmake_minimum_required(VERSION 3.10)
project(chess-engine)

set(SOURCES
	src/main.cpp
)

set(HEADERS

)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED TRUE
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE $<$<CONFIG:Debug>:_DEBUG>
)

target_include_directories(${PROJECT_NAME}
	PRIVATE src
)