cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(union_find VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_subdirectory(src)
