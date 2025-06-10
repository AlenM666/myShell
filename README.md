# 🐚 myShell - A Minimal UNIX-like Shell in C++

`myShell` is a basic, modular UNIX-like shell implemented in C++ with support for command parsing, piping, and a few built-in commands (`cd`, `help`, `exit`, etc.). It uses GNU Readline for interactive input and is organized with CMake for clean and real-world project structure.


## 📦 Features

- Built-in commands: `cd`, `exit`, `help`, `hello`
- Executes external commands (e.g., `ls`, `pwd`, etc.)
- Pipe support (`|`) for connecting commands
- Uses `readline` for advanced input and history
- Modular C++ codebase (split across multiple source/header files)
- Real-world structure with `CMake`

---

## 🛠️ Build Instructions

### Requirements:

- C++17 compiler (e.g., `g++`, `clang++`)
- CMake ≥ 3.10
- GNU Readline development library

### Install dependencies (Ubuntu/Debian):

```bash
sudo apt update
sudo apt install build-essential cmake libreadline-dev
```

### Clone and Build:

```bash
git clone https://github.com/AlenM666/myShell
cd myShell
mkdir build && cd build
cmake ..
make
```

### Run:

```bash
./myShell
```

---

## 📖 Built-in Commands

- `cd [dir]`: Change directory
- `exit`: Exit the shell
- `help`: Display supported features
- `hello`: Greet the current user

---

## 🚀 Example Usage

```sh
>>> ls -la
>>> cd ..
>>> pwd
>>> cat file.txt | grep error
>>> exit
```

---

## 📚 References

- [GNU Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [execvp() - Linux Man Page](https://man7.org/linux/man-pages/man3/execvp.3.html)
- [pipe() - Linux Man Page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [dup2() - Linux Man Page](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [fork() - Linux Man Page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [UNIX Shell Guide - TLDP](https://tldp.org/LDP/abs/html/)

---

## 📃 License

MIT License — feel free to use and modify.
