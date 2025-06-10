#include "builtins.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

namespace mysh {

int handle_builtin(const std::vector<std::string>& args) {
    if (args.empty()) return 0;

    const std::string& cmd = args[0];
    if (cmd == "exit") {
        exit(0);
    } else if (cmd == "cd") {
        const char* path = args.size() > 1 ? args[1].c_str() : getenv("HOME");
        if (chdir(path) != 0) {
            perror("cd failed");
        }
        return 1;
    }

    return 0;
}

}
