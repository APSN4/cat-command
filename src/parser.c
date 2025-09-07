//
// Created by APSN4 on 9/7/2025.
//

#include <stdio.h>
#include <stdlib.h>

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

    char str[8192];
    while (fgets(str, fileSize, pFile) != NULL) {
        printf("%s", str);
    }
    fclose(pFile);
}