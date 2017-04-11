cmake_minimum_required(VERSION 2.8)
project(honeycrisp)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/honeycrisp)

set(HONEYCRISP_SRCS
${PROJECT_SOURCE_DIR}/2d/geometry/rect.cpp
${PROJECT_SOURCE_DIR}/2d/scene.cpp
${PROJECT_SOURCE_DIR}/2d/sprite.cpp
${PROJECT_SOURCE_DIR}/2d/spritesheet.cpp
${PROJECT_SOURCE_DIR}/2d/surface.cpp
${PROJECT_SOURCE_DIR}/base/game.cpp
${PROJECT_SOURCE_DIR}/base/gameobject.cpp
${PROJECT_SOURCE_DIR}/base/thread.cpp
${PROJECT_SOURCE_DIR}/base/timer.cpp
${PROJECT_SOURCE_DIR}/renderer/texture.cpp
${PROJECT_SOURCE_DIR}/renderer/texturemanager.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -O1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -v")

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${HONEYCRISP_SRCS})

target_link_libraries(honeycrisp ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2GFX_LIBRARY})
