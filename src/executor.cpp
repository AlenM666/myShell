#include "executor.h"
#include "builtins.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

namespace mysh {

void execute_command(const std::vector<std::string>& args) {
    if (args.empty()) return;

    if (handle_builtin(args)) return;

    std::vector<char*> argv;
    for (const auto& arg : args) {
        argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        execvp(argv[0], argv.data());
        perror("Execution failed");
        exit(1);
    } else {
        wait(nullptr);
    }
}

void execute_pipe(const std::vector<std::string>& args, const std::vector<std::string>& pipe_args) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return;
    }

    pid_t p1 = fork();
    if (p1 < 0) {
        perror("Fork failed");
        return;
    }

    if (p1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        std::vector<char*> argv;
        for (const auto& arg : args)
            argv.push_back(const_cast<char*>(arg.c_str()));
        argv.push_back(nullptr);

        execvp(argv[0], argv.data());
        perror("Exec 1 failed");
        exit(1);
    } else {
        pid_t p2 = fork();
        if (p2 < 0) {
            perror("Fork failed");
            return;
        }

        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);

            std::vector<char*> argv;
            for (const auto& arg : pipe_args)
                argv.push_back(const_cast<char*>(arg.c_str()));
            argv.push_back(nullptr);

            execvp(argv[0], argv.data());
            perror("Exec 2 failed");
            exit(1);
        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(p1, nullptr, 0);
            waitpid(p2, nullptr, 0);
        }
    }
}

}
