

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source = argv[1];
    char *destination = argv[2];

    // Check if source file exists
    if (access(source, F_OK) == -1) {
        fprintf(stderr, "Error: Source file '%s' does not exist.\n", source);
        exit(EXIT_FAILURE);
    }

    // Attempt to rename (move) the file
    if (rename(source, destination) != 0) {
        fprintf(stderr, "Error: Failed to move '%s' to '%s': %s\n", source, destination, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Successfully moved '%s' to '%s'\n", source, destination);
    return EXIT_SUCCESS;
}

