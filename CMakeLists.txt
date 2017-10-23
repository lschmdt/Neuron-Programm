cmake_minimum_required(VERSION 2.6)

project(Neuron)
set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(gtest/include gtest)

add_executable(Neuron Neuron.cpp Network.cpp mainNeuron.cpp Constant.hpp)
add_executable(Neuron_unittest1 Neuron.cpp Network.cpp Constant.hpp Unittest1.cpp)

target_link_libraries(Neuron_unittest1 gtest gtest_main)
add_test(Neuron_unittest1 Neuron_unittest1)
