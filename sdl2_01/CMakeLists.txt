cmake_minimum_required(VERSION 3.10)

project(SDL2Test)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)
find_package(jsoncpp REQUIRED)

file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(${SDL2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} spdlog::spdlog jsoncpp_lib)

# Copy res dir to the binary directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# copy config.json
file(COPY conf.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(MSVC)
    file(COPY ${SDL2_DIR}/lib/x64/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${jsoncpp_DIR}/../../../bin/jsoncpp.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()