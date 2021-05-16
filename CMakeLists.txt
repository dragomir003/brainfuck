cmake_minimum_required(VERSION 3.10)

project(brainfuck)

include(CTest)

add_subdirectory(brainfuck)
add_subdirectory(brainfuck-lib)
add_subdirectory(tests)