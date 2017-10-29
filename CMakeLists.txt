cmake_minimum_required(VERSION 3.8)
project(calculator_cpp)

set(CMAKE_CXX_STANDARD 11)
set(LIB_FILES cal_expr.cpp)
set(SOURCE_FILES main.cpp)
add_library(calculator ${LIB_FILES})
add_executable(foo ${SOURCE_FILES})
target_link_libraries(foo calculator)