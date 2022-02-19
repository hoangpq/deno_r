cmake_minimum_required(VERSION 3.21)
project(r_binding)

set(CMAKE_CXX_STANDARD 14)

include_directories(r_sys/r)
include_directories(r_sys/src/include)
include_directories(r_sys/src/include/R_ext)

add_executable(r_binding
        r_sys/src/binding.cc
        r_sys/src/binding.h)
