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

# Set compiler flags for debug version
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wextra -Werror -Og")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

# Link Raylib library to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE ${raylib_LIBRARIES})

# Additional linker flags
target_link_libraries(${PROJECT_NAME} PRIVATE -lglfw -lm -ldl -lpthread)
