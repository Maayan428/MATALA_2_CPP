# SquareMat Project

**Name:**: Maayan Turgeman
**ID**: 209948058
**Email**: maayan428@gmail.com

---

## Description
This project implements a **Square Matrix (`SquareMat`)** class in C++ using raw dynamic memory (without STL containers) and **operator overloading**. It includes a full test suite with the `doctest` framework.

---

## File Structure

| File             | Description |
|------------------|-------------|
| `SquareMat.hpp/cpp` | Class definition and implementation of `SquareMat`, including operator overloading, helper methods, and memory management. |
| `main.cpp`           | Demo program that demonstrates all functionality of the matrix class. |
| `Test.cpp`           | Unit tests validating all public functionality using `doctest`. |
| `doctest.h`          | Header-only testing framework (version 2.4.12). |
| `Makefile`           | Build automation: compile, run, test, valgrind, and cleanup. |
| `submission.txt`     | Required file for Moodle submission (ID, GitHub link, commit hash). |

---

## How to Use

### Build and Run Demo:
```bash
make Main
./Main
```

### Run Unit Tests:
```bash
make test
```

### Run Memory Check:
```bash
make valgrind
```

### Clean Up Build Files:
```bash
make clean
```

---

## Environment
Compiled and tested on Ubuntu 24.04 (Mac Parallels VM), with g++ 11.