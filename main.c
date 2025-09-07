#include <stdio.h>
#include "src/parser.h"

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        print_plain_text(argv[1]);
    } else {
        printf("Please choose a file.");
    }
    return 0;
}