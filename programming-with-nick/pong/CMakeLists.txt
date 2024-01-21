# cmake_minimum_required(VERSION 3.10)
#
# project(Pong)
#
# set(SOURCES src/main.c)
#
# add_executable(${PROJECT_NAME} ${SOURCES})
#
# target_link_libraries(${PROJECT_NAME} PUBLIC "/usr/local/lib/libraylib.so.450")

cmake_minimum_required(VERSION 3.12)

project(pong)

set(CMAKE_CXX_STANDARD 11)

find_package(raylib REQUIRED)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${raylib_LIBRARIES})
