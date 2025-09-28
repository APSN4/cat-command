//
// Created by APSN4 on 9/20/2025.
//

#include <string.h>
#include <stdio.h>
#include "arguments.h"

#include <stdbool.h>

const char *reserve_args[] = {
    "-A", "--show-all",
    "-b", "--number-nonblank",
    "-e", "-E", "--show-ends",
    "-n", "--number",
    "-s", "--squeeze-blank",
    "-t", "-T", "--show-tabs",
    "-v", "--show-nonprinting",
    "--help", "--version"
};

static const char *default_text = "Hey! No command found. Try --help for usage :)\n";
static const char *help_text =
"Usage: %s [OPTION]... [FILE]...\n"
"Concatenate FILE(s) to standard output. With no FILE, or when FILE is -, read standard input.\n"
"\n"
"Options:\n"
"  -A, --show-all           equivalent to -vET (show nonprinting, show tabs as ^I, show line ends as $)\n"
"  -b, --number-nonblank    number nonempty output lines\n"
"  -e                       equivalent to -vE (show nonprinting; show line ends as $)\n"
"  -E, --show-ends          display $ at end of each line\n"
"  -n, --number             number all output lines\n"
"  -s, --squeeze-blank      suppress repeated empty output lines\n"
"  -t                       equivalent to -vT (show nonprinting; show TABs as ^I)\n"
"  -T, --show-tabs          display TAB characters as ^I\n"
"  -v, --show-nonprinting   use ^ and M- notation, except for TAB and end of line\n"
"      --help               display this help and exit\n"
"      --version            output version information and exit\n"
"\n"
"Notes:\n"
"  - Options -e and -t are shorthands that also imply -v.\n"
"  - FILE \"-\" means standard input.\n"
"\n"
"Examples:\n"
"  %s file                  # print file to stdout\n"
"  %s -n file1 file2        # number all output lines from two files\n"
"  %s -b src.c              # number only nonblank lines\n"
"  %s -A README             # show nonprinting, tabs, and line ends\n"
"  %s -s log.txt            # squeeze multiple blank lines\n"
"  %s -T Makefile    # visualize TABs while paging\n"
"  %s --help                # show this help\n";


struct cat_options {
    bool number_lines;           // -n, --number
    bool number_nonblank;        // -b, --number-nonblank
    bool show_ends;              // -e, --show-ends
    bool show_tabs;              // -t, --show-tabs
    bool show_nonprinting;       // -v, --show-nonprinting
    bool squeeze_blank;          // -s, --squeeze-blank
    bool show_all;               // -A, --show-all
    bool help;                   // --help
    bool version;                // --version
} cat_options;

// TODO: implement logic to handle function arguments
bool process_arguments(int argc, char* argv[]) {
    const int len_commands = sizeof(reserve_args) / sizeof(reserve_args[0]);
    for (int i = 0; i < len_commands; i++) {
        for (int j = 0; j < argc; j++) {
            if (strcmp(reserve_args[i], argv[j]) == 0) {
                // printf("used: %s\n", reserve_args[i]);
                switch (i) {
                    case 0:
                    case 1: cat_options.show_all = true;
                            break;
                    case 2:
                    case 3: cat_options.number_nonblank = true;
                            break;
                    case 4:
                    case 5:
                    case 6: cat_options.show_ends = true;
                            break;
                    case 7:
                    case 8: cat_options.number_lines = true;
                            break;
                    case 9:
                    case 10: cat_options.squeeze_blank = true;
                            break;
                    case 11:
                    case 12:
                    case 13: cat_options.show_tabs = true;
                            break;
                    case 14:
                    case 15: cat_options.show_nonprinting = true;
                            break;
                    case 16: cat_options.help = true;
                            break;
                    case 17: cat_options.version = true;
                            break;
                }
            }
        }
    }
    if (cat_options.help) {
        printf(help_text, argv[0], argv[0], argv[0], argv[0], argv[0], argv[0], argv[0], argv[0]);
        return true;
    }
    if (!cat_options.number_lines &&
    !cat_options.number_nonblank &&
    !cat_options.show_ends &&
    !cat_options.show_tabs &&
    !cat_options.show_nonprinting &&
    !cat_options.squeeze_blank &&
    !cat_options.show_all) {
        printf(default_text);
        return true;
    }
    return false;
}
