#pragma once
#include <vector>
#include <string>

namespace mysh {
    void execute_command(const std::vector<std::string>& args);
    void execute_pipe(const std::vector<std::string>& args, const std::vector<std::string>& pipe_args);
}
