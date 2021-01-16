cmake_minimum_required(VERSION 3.9)
project(pyzmodlib)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER g++)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS "-Wall -O3 -luio")
set(CPLUS_INCLUDE_PATH "/usr/include/python3.7m")
find_package(pybind11 REQUIRED)

add_definitions(-DLINUX_APP)

add_library(zmodlib zmoddac1411 zmodadc1410 zmod zmoddac1411.cpp zmodadc1410.cpp zmod.cpp dma.c flash.c libaxidma.c reg.c utils.c)

pybind11_add_module(pyzmodlib pyzmodlib.cpp)

target_link_libraries(pyzmodlib PRIVATE zmodlib)
