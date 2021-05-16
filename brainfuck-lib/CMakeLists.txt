project(brainfuck-lib)

add_library(brainfuck-lib STATIC "src/lib.c")
target_include_directories(brainfuck-lib PUBLIC "include/")