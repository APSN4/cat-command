//
// Created by APSN4 on 9/20/2025.
//

#include <string.h>
#include <stdio.h>
#include "arguments.h"

const char *reserve_args[] = {
    "-A", "--show-all",
    "-b", "--number-nonblank",
    "-e", "-E", "--show-ends",
    "-n", "--number",
    "-s", "--squeeze-blank",
    "-t", "-T", "--show-tabs",
    "-u",
    "-v", "--show-nonprinting",
    "--help", "--version"
};

// TODO: implement logic to handle function arguments
void check_use_arguments(int argc, char* argv[]) {
    const int len_commands = sizeof(reserve_args) / sizeof(reserve_args[0]);
    for (int i = 0; i < len_commands; i++) {
        for (int j = 0; j < argc; j++) {
            if (strcmp(reserve_args[i], argv[j]) == 0) {
                printf("used: %s\n", reserve_args[i]);
            }
        }
    }
}
