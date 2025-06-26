cmake_minimum_required(VERSION 3.30)
project(algorithm-cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON)

find_package(fmt CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)

set(PROTO_FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../proto)
set(PROTO_FILES
    ${PROTO_FILE_DIR}/example.proto
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_library(proto STATIC ${PROTO_HDRS} ${PROTO_SRCS})
target_include_directories(proto
    PUBLIC ${CMAKE_BINARY_DIR}
)
target_link_libraries(proto
    PRIVATE protobuf::libprotobuf
)

include_directories(${PROTO_HDR})

add_executable(write_demo src/write_demo.cpp)
target_link_libraries(write_demo
    PRIVATE proto
    PRIVATE fmt::fmt
)

add_executable(read_demo src/read_demo.cpp)
target_link_libraries(read_demo
    PRIVATE proto
    PRIVATE fmt::fmt
)
