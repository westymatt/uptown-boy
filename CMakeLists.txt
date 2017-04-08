cmake_minimum_required(VERSION 2.8)

project(uptownboy)

set(CMAKE_INSTALL_RPATH "")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${CMAKE_SOURCE_DIR}/honeycrisp/src/)
include_directories("/usr/local/include")

add_subdirectory(honeycrisp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -O1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -v")

set(UPTOWNBOY_SRCS
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)

set(uptownboy_VERSION_MAJOR 0)
set(uptownboy_VERSION_MINOR 1)

add_executable(
  uptownboy
  ${UPTOWNBOY_SRCS}
)

target_link_libraries(uptownboy honeycrisp)
file(COPY src/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
