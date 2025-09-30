#include <stdio.h>
#include <stdlib.h>

#include "src/arguments.h"
#include "src/parser.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        const bool is_exit = process_arguments(argc, argv);
        if (is_exit)
            exit(EXIT_FAILURE);
        print_plain_text(argv[1]);
    } else {
        printf("Please choose a file.\n");
    }
    return 0;
}
