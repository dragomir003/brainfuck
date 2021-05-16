project(brainfuck)

add_executable(brainfuck "src/main.c")
target_link_libraries(brainfuck PRIVATE brainfuck-lib)