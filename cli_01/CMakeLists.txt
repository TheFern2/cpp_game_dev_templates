cmake_minimum_required(VERSION 3.10)
project(MyTemplate VERSION 1.0.0 LANGUAGES CXX)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

find_package(spdlog REQUIRED)
find_package(jsoncpp REQUIRED)

file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} spdlog::spdlog jsoncpp_lib)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Copy res dir to the binary directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# copy config.json
file(COPY conf.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(MSVC)
   # copy jsoncpp
   file(COPY ${jsoncpp_DIR}/../../../bin/jsoncpp.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()