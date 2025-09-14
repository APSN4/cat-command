//
// Created by APSN4 on 9/7/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void print_plain_text(char* path) {
    FILE* pFile;
    long fileSize;

    pFile = fopen(path, "r");
    if (pFile == NULL) {
        printf("Error While opening file.");
        exit(1);
    }
    fseek(pFile, 0, SEEK_END);
    fileSize = ftell(pFile);
    rewind(pFile);

    char *str = malloc(MEM_BLOCK);
    long pos;
    while (fgets(str, *str, pFile) != NULL) {
        if (strchr(str, '\n') == NULL) {
            char *temp = realloc(str, MEM_BLOCK * 2);
            if (temp == NULL) {
                printf("Could not reallocate memory!\n");
                exit(1);
            }
            str = temp;
            temp = NULL;
            continue;
        }
        printf("%s", str);

        char *temp = realloc(str, MEM_BLOCK);
        if (temp == NULL) {
            printf("Could not reallocate memory!\n");
            exit(1);
        }
        str = temp;
        temp = NULL;
    }
    free(str);
    fclose(pFile);
}