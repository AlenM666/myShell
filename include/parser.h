#pragma once
#include <vector>
#include <string>

namespace mysh {
    int process_input(const std::string& input,
                      std::vector<std::string>& args,
                      std::vector<std::string>& pipe_args);
}
