#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    // Check if too many args are provided or invalid combination
    if (argc > 3 || (argc == 3 && strcmp(argv[1], "--") != 0)) {
        fprintf(stderr, "USAGE: fib [outfile]\n");
        return 1;
    }

    FILE* out = stdout; // Default to stdout unless user wants a file

    // If "--" is used, treat the next argument as the output file
    if (argc == 3 && strcmp(argv[1], "--") == 0) {
        out = fopen(argv[2], "w");
        if (!out) {
            fprintf(stderr, "Could not open file: %s\n", argv[2]);
            return 1;
        }
    }
    // If "-" is provided, explicitly use stdout
    else if (argc == 2 && strcmp(argv[1], "-") == 0) {
        out = stdout;
    }
    // Otherwise assume the argument is a filename
    else if (argc == 2) {
        out = fopen(argv[1], "w");
        if (!out) {
            fprintf(stderr, "Could not open file: %s\n", argv[1]);
            return 1;
        }
    }

    // Print a simple header first
    fprintf(out, "Fibonacci numbers:\n");

    // Generate the first 10 Fibonacci numbers
    int prev = 0;
    int curr = 1;

    for (int i = 0; i < 10; i++) {
        fprintf(out, "%d\n", prev);

        // Move the sequence forward
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }

    // Only close the file if we actually opened one
    if (out != stdout) {
        fclose(out);
    }

    return 0;
}
