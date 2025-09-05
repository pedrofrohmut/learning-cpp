cmake_minimum_required(VERSION 3.16)
project(HelloSDL3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL3_DIR $ENV{HOME}/programming/lib/SDL3)

if(NOT EXISTS ${SDL3_DIR})
  message(FATAL_ERROR "SDL3 not found at: " ${SDL3_DIR})
endif()

add_subdirectory(${SDL3_DIR} ${CMAKE_BINARY_DIR}/SDL3)
add_executable(hello-sdl3 src/main.cpp)
target_link_libraries(hello-sdl3 PRIVATE SDL3)
