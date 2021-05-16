project(tests)

link_libraries(criterion brainfuck-lib)

add_executable(basic "src/test.c")

add_test(NAME basic COMMAND basic)