# SquareMat Project:

**Name:** Maayan Turgeman
**ID:** 209948058
**Email:** maayan428@gmail.com

---

## Description
This project implements a class called **`SquareMat`** for working with square matrices of real numbers in C++. 
The implementation uses **dynamic memory allocation** with raw pointers (no `vector`, `array` or any other STL containers allowed), and demonstrates in-depth use of **operator overloading** in C++. 

The class supports arithmetic operations (addition, subtraction, multiplication, scalar operations), logic and comparison operators, access via index notation, and advanced features like **transpose**, **matrix exponentiation**, and **determinant calculation** using recursion with minor extraction. 

All functionalities were implemented from scratch, including memory management (with `new` and `delete`), exception handling, and input validation. 

In addition, the project includes a **full set of unit tests** using the [`doctest`](https://github.com/doctest/doctest) framework to validate correctness and edge cases, and it passed memory checks via **Valgrind**.

---

## File Structure

| File             | Description |
|------------------|-------------|
| `SquareMat.hpp`      | Header file that defines the `SquareMat` class, its methods, and the overloaded operators. |
| `SquareMat.cpp`      | Implements all the logic of the `SquareMat` class, including operator overloading and helper methods. |
| `main.cpp`           | Demonstrates how to create and manipulate square matrices using all the supported operations. |
| `Test.cpp`           | Contains a comprehensive suite of unit tests using the `doctest` framework, covering edge cases and expected behavior. |
| `doctest.h`          | The testing framework used to write and run all the unit tests. Header-only and included locally. |
| `Makefile`           | Allows building the demo (`Main`), running tests (`Test`), checking for memory leaks (via `valgrind`), and cleaning up build files. |

---

## How to Use:

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

## Environment:
Compiled and tested on **Ubuntu 24.04 (running in Parallels on Mac)** with **g++ 11** and `make`. 
Valgrind version used: `3.22.0`