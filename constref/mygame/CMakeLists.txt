cmake_minimum_required(VERSION 3.16)
project(MyGame)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -O0 -Wall -Wextra -Wpedantic)
else()
    add_compile_options(-O2)
endif()


# SDL3
set(SDL3_DIR $ENV{HOME}/programming/lib/SDL3)
if(NOT EXISTS ${SDL3_DIR})
  message(FATAL_ERROR "SDL3 not found at: " ${SDL3_DIR})
endif()
add_subdirectory(${SDL3_DIR} ${CMAKE_BINARY_DIR}/SDL3)


# SDL3_image
set(SDL3_IMAGE_DIR $ENV{HOME}/programming/lib/SDL_image)
if(NOT EXISTS ${SDL3_IMAGE_DIR})
    message(FATAL_ERROR "SDL3_image not found at: " ${SDL3_IMAGE_DIR})
endif()
add_subdirectory(${SDL3_IMAGE_DIR} ${CMAKE_BINARY_DIR}/SDL_image)


add_executable(mygame src/main.cpp)
target_link_libraries(mygame PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(mygame PRIVATE -g -O0)
    target_link_options(mygame PRIVATE -g)
endif()


target_include_directories(mygame PRIVATE
    ${SDL3_DIR}/include/SDL3
    ${SDL3_IMAGE_DIR}/include/SDL3_image
)
