# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Sources
MAIN_SRCS = main.cpp SquareMat.cpp
TEST_SRCS = Test.cpp SquareMat.cpp

# Executables
MAIN_EXE = Main
TEST_EXE = Test

# Targets
all: $(MAIN_EXE)

# Build the main program
Main: $(MAIN_SRCS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(MAIN_SRCS)

# Build and run tests
test: $(TEST_SRCS) doctest.h
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_SRCS)
	./$(TEST_EXE)

# Run valgrind on the main executable
valgrind: Main
	$(VALGRIND) ./$(MAIN_EXE)

# Clean all build files
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE) *.o