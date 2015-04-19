cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -O3 -ffast-math")

include_directories(./)

project(neuralinterface)
add_library(neuralinterface SHARED NeuralInterface.cpp)

project(BasicExample)
add_executable(BasicExample example/BasicExample.cpp)
target_link_libraries(BasicExample neuralinterface)

