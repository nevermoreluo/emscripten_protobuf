project (emccTest)
cmake_minimum_required(VERSION 3.10)

option(JS_ONLY "Compiles to native JS (No WASM)" OFF)
set(GEN_PB OFF)

add_subdirectory(src/proto proto.out)

add_definitions(-std=c++11 -O3)
include_directories(src)

include_directories(${PROTO_INCLUDE_DIRS})
file(GLOB SOURCES src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")



add_library(${PROJECT_NAME} STATIC
        ${SOURCES}
        )

target_link_libraries(${PROJECT_NAME}
        ${CMAKE_DL_LIBS} 
		proto
		)

# if(JS_ONLY)
# 	message(STATUS "Setting compilation target to native JavaScript")
# 	set(CMAKE_EXECUTABLE_SUFFIX ".js")
# 	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_main]'")
# else(JS_ONLY)
# 	message(STATUS "Setting compilation target to WASM")
# 	set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
# 	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_main]'")
# endif(JS_ONLY)

