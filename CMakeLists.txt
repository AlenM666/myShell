cmake_minimum_required(VERSION 3.10)
project(myShell)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_executable(myShell ${SOURCES})
# add_executable(myShell
#     src/main.cpp
#     src/shell.cpp
#     src/builtins.cpp
#     src/parser.cpp
#     src/executor.cpp
#     src/utils.cpp
# )

# Link Readline library
find_library(READLINE_LIB readline)
target_link_libraries(myShell ${READLINE_LIB})


