cmake_minimum_required(VERSION 3.9)
project(zmoddac1411)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER g++)

set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS "-Wall -O3 -luio")
set(CPLUS_INCLUDE_PATH "/usr/include/python3.7m")
find_package(pybind11 REQUIRED)

add_definitions(-DLINUX_APP)

pybind11_add_module(zmoddac1411 zmod SHARED zmoddac1411.cpp zmoddac1411_wrap.cpp zmod.cpp dma.c flash.c libaxidma.c reg.c utils.c)
