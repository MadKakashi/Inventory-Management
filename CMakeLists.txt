cmake_minimum_required(VERSION 3.10)

project(InventoryManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
