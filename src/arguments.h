//
// Created by APSN4 on 9/20/2025.
//

#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include <stdbool.h>

extern const char *reserve_args[];

int* process_arguments(int argc, char* argv[], int *count_files);

#endif //ARGUMENTS_H
