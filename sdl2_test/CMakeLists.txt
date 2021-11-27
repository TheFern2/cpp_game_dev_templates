cmake_minimum_required(VERSION 3.10)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test src/main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})

if(MSVC)
    file(COPY ${SDL2_DIR}/lib/x64/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()