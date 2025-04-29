#include "SquareMat.hpp"
#include <cmath>
using namespace my_matrix;

// Private helper functions

// Initializes the matrix by allocating memory and setting all elements to zero.
void SquareMat::initMatrix() {
    mat = new double*[size];
    for (size_t i = 0; i < size; ++i) {
        mat[i] = new double[size]();
    }
}

// Frees the allocated memory of the matrix.
void SquareMat::clearMatrix() {
    for (size_t i = 0; i < size; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
    mat = nullptr;
}

// Copies the content from another matrix into this matrix.
void SquareMat::copyMatrix(const SquareMat& other) {
    size = other.size;
    initMatrix();
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            mat[i][j] = other.mat[i][j];
}

// Constructors and Destructor

SquareMat::SquareMat(size_t n) : size(n) {
    if (n == 0) throw std::invalid_argument("Matrix size must be greater than zero");
    initMatrix();
}

SquareMat::SquareMat(const SquareMat& other) {
    copyMatrix(other);
}

SquareMat::~SquareMat() {
    clearMatrix();
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        clearMatrix();
        copyMatrix(other);
    }
    return *this;
}

// Arithmetic Operators

SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must match for addition");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must match for subtraction");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = -mat[i][j];
    return result;
}

// Multiplies two square matrices using the triple-loop algorithm.
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must match for multiplication");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            for (size_t k = 0; k < size; ++k)
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = mat[i][j] * scalar;
    return result;
}

namespace my_matrix {
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Matrix sizes must match for element-wise multiplication");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = mat[i][j] * other.mat[i][j];
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero is not allowed");
    }
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = std::fmod(mat[i][j], scalar);
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) throw std::invalid_argument("Cannot divide by zero");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[i][j] = mat[i][j] / scalar;
    return result;
}

// Raises the matrix to an integer power efficiently using the square-and-multiply method.
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) throw std::invalid_argument("Negative powers not supported");
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i) result.mat[i][i] = 1.0;
    SquareMat base(*this);
    while (power > 0) {
        if (power % 2 == 1) result = result * base;
        base = base * base;
        power /= 2;
    }
    return result;
}

// Compound Assignment Operators

SquareMat& SquareMat::operator+=(const SquareMat& other) { *this = *this + other; return *this; }
SquareMat& SquareMat::operator-=(const SquareMat& other) { *this = *this - other; return *this; }
SquareMat& SquareMat::operator*=(const SquareMat& other) { *this = *this * other; return *this; }
SquareMat& SquareMat::operator*=(double scalar) { *this = *this * scalar; return *this; }
SquareMat& SquareMat::operator/=(double scalar) { *this = *this / scalar; return *this; }
SquareMat& SquareMat::operator%=(const SquareMat& other) { *this = *this % other; return *this; }
SquareMat& SquareMat::operator%=(int scalar) { *this = *this % scalar; return *this; }

// Increment / Decrement Operators

SquareMat& SquareMat::operator++() {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            ++mat[i][j];
    return *this;
}

SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this);
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--() {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            --mat[i][j];
    return *this;
}

SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this);
    --(*this);
    return temp;
}

// Transpose

SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.mat[j][i] = mat[i][j];
    return result;
}

// Element Access

double* SquareMat::operator[](int row) {
    if (row < 0 || (size_t)row >= size) throw std::out_of_range("Row index out of range");
    return mat[row];
}

const double* SquareMat::operator[](int row) const {
    if (row < 0 || (size_t)row >= size) throw std::out_of_range("Row index out of range");
    return mat[row];
}

// Comparison Operators

bool SquareMat::operator==(const SquareMat& other) const { return sum() == other.sum(); }
bool SquareMat::operator!=(const SquareMat& other) const { return !(*this == other); }
bool SquareMat::operator<(const SquareMat& other) const { return sum() < other.sum(); }
bool SquareMat::operator<=(const SquareMat& other) const { return sum() <= other.sum(); }
bool SquareMat::operator>(const SquareMat& other) const { return sum() > other.sum(); }
bool SquareMat::operator>=(const SquareMat& other) const { return sum() >= other.sum(); }

// Determinant

// Calculates the determinant of the matrix using the method of minors and cofactors.
double SquareMat::operator!() const {
    if (size == 1) return mat[0][0];
    if (size == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    double det = 0.0;
    for (size_t col = 0; col < size; ++col) {
        det += (col % 2 == 0 ? 1 : -1) * mat[0][col] * extractMinor(0, col).operator!();
    }
    return det;
}

// Helper Functions

double SquareMat::sum() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            total += mat[i][j];
    return total;
}

// Extracts the minor matrix by removing a specific row and column.
SquareMat SquareMat::extractMinor(int rowToSkip, int colToSkip) const {
    SquareMat minor(size - 1);
    for (size_t i = 0, mi = 0; i < size; ++i) {
        if (static_cast<int>(i) == rowToSkip) continue;
        for (size_t j = 0, mj = 0; j < size; ++j) {
            if (static_cast<int>(j) == colToSkip) continue;
            minor.mat[mi][mj] = mat[i][j];
            ++mj;
        }
        ++mi;
    }
    return minor;
}

// Output Operator
namespace my_matrix {
std::ostream& operator<<(std::ostream& os, const SquareMat& m) {
    for (size_t i = 0; i < m.size; ++i) {
        for (size_t j = 0; j < m.size; ++j) {
            os << m.mat[i][j] << (j == m.size - 1 ? "" : " ");
        }
        os << std::endl;
    }
    return os;
}
}