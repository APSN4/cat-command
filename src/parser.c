//
// Created by APSN4 on 9/7/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void print_plain_text(char* path) {
    FILE *pFile = fopen(path, "r");
    if (pFile == NULL) {
        printf("Error While opening %s", path);
        exit(1);
    }
    fseek(pFile, 0, SEEK_END);
    rewind(pFile);

    int size_buf = MEM_BLOCK;
    char *str = calloc(size_buf, sizeof(char));
    char str_new[MEM_BLOCK];
    while (fgets(str_new, MEM_BLOCK, pFile) != NULL) {
        if (strchr(str_new, '\n') == NULL) {
            size_buf *= 2;
            char *temp = realloc(str, size_buf);
            if (temp == NULL) {
                printf("Could not reallocate memory!\n");
                exit(1);
            }
            str = temp;
            strcat(str, str_new);
            temp = NULL;
            continue;
        }
        strcat(str, str_new);
        printf("%s", str);

        str[0] = '\0';
        size_buf = MEM_BLOCK;
    }
    printf("%s", str);
    free(str);
    fclose(pFile);
}

void process_files(char* paths[]) {

}