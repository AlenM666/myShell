#include "utils.h"
#include <unistd.h>
#include <iostream>
#include <limits.h>
#include <stdlib.h>

namespace mysh {

void clear_screen() {
    const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void print_dir() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd))) {
        std::cout << "\nDir: " << cwd << "\n";
    }
}

}
