#include "parser.h"
#include <sstream>
#include <algorithm>

namespace mysh {

int process_input(const std::string& input,
                  std::vector<std::string>& args,
                  std::vector<std::string>& pipe_args) {
    std::stringstream ss(input);
    std::string token;
    bool pipe_found = false;

    while (ss >> token) {
        if (token == "|") {
            pipe_found = true;
            continue;
        }

        if (!pipe_found)
            args.push_back(token);
        else
            pipe_args.push_back(token);
    }

    if (!args.empty() && args[0] == "exit")
        exit(0);

    if (pipe_found) return 2;
    return 1;
}

}
