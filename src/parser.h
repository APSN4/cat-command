//
// Created by APSN4 on 9/7/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

#define COMPLETE 1
#define ERROR 0
#define MEM_BLOCK 128

/* min/max */
#undef min
#undef max
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int find_end_line(int* now_pointer, int* last_pointer);
void print_plain_text(char* path);

#endif //PARSER_H
