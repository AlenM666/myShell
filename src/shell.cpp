#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "utils.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

namespace mysh {

void init_shell() {
    clear_screen();
    std::cout << "Welcome to myShell!" << std::endl;
    const char* user = getenv("USER");
    std::cout << "User: @" << (user ? user : "unknown") << "\n\n";
}

void run_shell() {
    std::string input;
    std::vector<std::string> args, pipe_args;
    int exec_flag;

    while (true) {
        print_dir();

        char* buf = readline(">>> ");
        if (!buf || std::string(buf).empty()) {
            free(buf);
            continue;
        }

        add_history(buf);
        input = buf;
        free(buf);

        exec_flag = process_input(input, args, pipe_args);

        if (exec_flag == 1) execute_command(args);
        else if (exec_flag == 2) execute_pipe(args, pipe_args);

        args.clear();
        pipe_args.clear();
    }
}

}
