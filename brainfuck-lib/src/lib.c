#include <brainfuck.h>

#include <stdio.h>

static const char *bf_error_msg[] = { "No error" };
static int bf_error_code = 0;

int brainfuck(const char *file) {
    return bf_error_code;
}

void bf_perror(const char *msg) {
    fprintf(stderr, "%s: %s", msg, bf_error_msg[bf_error_code]);
}