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

    int cap_str = MEM_BLOCK; // ready buffer
    int size_buf = MEM_BLOCK; // read buffer
    char *str = calloc(cap_str, sizeof(char));
    char *str_new = calloc(size_buf, sizeof(char));
    if (!str || !str_new) { printf("OOM\n"); exit(1); }

    while (fgets(str_new, size_buf, pFile) != NULL) {

        // double buffer if '\n' doesn't exists
        if (strchr(str_new, '\n') == NULL) {
            size_buf *= 2;

            char *tmp_new = realloc(str_new, size_buf);
            if (!tmp_new) { printf("Could not reallocate memory!\n"); exit(1); }
            str_new = tmp_new;
        }

        // guarantee size in str for add str_new
        size_t need = strlen(str) + strlen(str_new) + 1;
        if (need > (size_t)cap_str) {
            while (need > (size_t)cap_str) cap_str *= 2;
            char *tmp = realloc(str, cap_str);
            if (!tmp) { printf("Could not reallocate memory!\n"); exit(1); }
            str = tmp;
        }

        strcat(str, str_new);

        // if it's the end, reset the buffer
        if (str[strlen(str) - 1] == '\n') {
            printf("%s", str);
            str[0] = '\0';

            if ((size_t)size_buf > 1024) { // 1kb
                size_buf = MEM_BLOCK;
                char *tmp_new2 = realloc(str_new, size_buf);
                if (tmp_new2) str_new = tmp_new2;
            }

            // if cap_str is huge, reset the buffer
            if ((size_t)cap_str > 1048576) { // 1mb
                cap_str = MEM_BLOCK;
                char *tmp_new3 = realloc(str, cap_str);
                if (tmp_new3) str = tmp_new3;
            }
        }
    }
    if (str[0] != '\0') printf("%s", str);
    free(str);
    free(str_new);
    fclose(pFile);
}

void process_files(char* paths[]) {

}