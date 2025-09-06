cmake_minimum_required(VERSION 3.16)
project(MyGame)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


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
target_include_directories(mygame PRIVATE ${SDL3_DIR}/include/SDL3 ${SDL3_IMAGE_DIR}/include/SDL3_image)
