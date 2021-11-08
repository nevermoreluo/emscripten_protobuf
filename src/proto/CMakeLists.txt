cmake_minimum_required(VERSION 3.10)
project(proto)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-fPIC)
#SET(Protobuf_USE_STATIC_LIBS ON) # edit by 7

set(Protobuf_INCLUDE_DIR /usr/local/include)
set(Protobuf_LIBRARIES /usr/local/lib)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
FILE(GLOB protofiles "${CMAKE_CURRENT_SOURCE_DIR}/protocol/*.proto")


if (GEN_PB AND UNIX)
    foreach(_file ${protofiles})
        get_filename_component(_filename ${_file} NAME)
        string(REPLACE ".proto" ".pb" file_tro ${_filename})
        execute_process(
                COMMAND /bin/bash -c "mkdir -p ${CMAKE_BINARY_DIR}/build/bin && ${Protobuf_PROTOC_EXECUTABLE} -o ${CMAKE_CURRENT_SOURCE_DIR}/../../props/macro/0/proto/${file_tro} -I ${CMAKE_CURRENT_SOURCE_DIR}/protocol/ ${_file}"
        )
    endforeach()
endif (GEN_PB AND UNIX)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${protofiles})

set(PROTO_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS} PARENT_SCOPE)

add_library(${PROJECT_NAME} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
#target_link_libraries(proto ${CMAKE_DL_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libprotobuf-lite.a -lpthread -lm -lz) # edit by 7
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${Protobuf_LIBRARIES} -lpthread -lm -lz)

