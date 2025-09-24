#include <stdio.h>
#include "src/parser.h"
#include "src/arguments.h"

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        process_arguments(argc, argv);
        print_plain_text(argv[1]);
    } else {
        printf("Please choose a file.");
    }
    return 0;
}