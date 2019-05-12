cmake_minimum_required(VERSION 3.0)
project(po)

file(GLOB srcs "*.cpp")
list(FILTER srcs EXCLUDE REGEX "tests.cpp")
list(FILTER srcs EXCLUDE REGEX "main.cpp")

add_executable(wzpo "main.cpp" ${srcs}) 
add_executable(wzpo_tests "tests.cpp" ${srcs})
