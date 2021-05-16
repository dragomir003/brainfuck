#include <stdio.h>
#include <stdlib.h>

#include <brainfuck.h>

#define HANDLE_ERROR(condition, msg) do {\
                                        if (condition) {\
                                            perror(msg);\
                                            exit(EXIT_FAILURE);\
                                        }\
                                    } while (0)

char* read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");

    HANDLE_ERROR(!fp, "Could not open the file");

    HANDLE_ERROR(fseek(fp, 0, SEEK_END), "Could not find end of the file");
    const long len = ftell(fp);
    HANDLE_ERROR(len < 0, "Could not get the size of the file.");
    HANDLE_ERROR(fseek(fp, 0, SEEK_SET), "Could not return to the beginning of the file");

    char *file = malloc(len + 1);
    HANDLE_ERROR(!file, "Could not allocate memory to store contents of the file");
    file[len] = 0;

    fread(file, sizeof *file, len, fp);

    HANDLE_ERROR(fclose(fp), "Could not close the file pointer");

    return file;
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* filename = argv[1];
    char *file = read_file(filename);

    puts(file);

    int code = brainfuck(file);

    if (code) {
        bf_perror("Brainfuck failed");
        exit(EXIT_FAILURE);
    }

    free(file);
}