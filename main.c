#include <stdio.h>
#include <stdlib.h>

#include "src/arguments.h"
#include "src/parser.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        int count_files;
        const int* files_i = process_arguments(argc, argv, &count_files);
        if (!files_i)
            exit(EXIT_FAILURE);
        for (int i = 0; i < count_files; i++) {
            print_plain_text(argv[files_i[i]]);
            printf("\n\n");
        }
    } else {
        printf("Please choose a file.\n");
    }
    return 0;
}
