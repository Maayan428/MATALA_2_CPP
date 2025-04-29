// maayan428@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

namespace my_matrix {

class SquareMat {
private:
    size_t size;
    double** mat;

    void initMatrix();
    void clearMatrix();
    void copyMatrix(const SquareMat& other);

public:
    // Constructors and Destructor
    SquareMat(size_t n);
    SquareMat(const SquareMat& other);
    ~SquareMat();
    SquareMat& operator=(const SquareMat& other);

    // Arithmetic Operators
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator^(int power) const;

    // Compound Assignment Operators
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);
    SquareMat& operator/=(double scalar);

    // Increment / Decrement Operators
    SquareMat& operator++();       // Prefix
    SquareMat operator++(int);     // Postfix
    SquareMat& operator--();       // Prefix
    SquareMat operator--(int);     // Postfix

    // Transpose
    SquareMat operator~() const;

    // Element Access
    double* operator[](int row);
    const double* operator[](int row) const;

    // Comparison Operators (based on sum of elements)
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Determinant
    double operator!() const;

    // Helper Functions
    double sum() const;
    SquareMat extractMinor(int rowToSkip, int colToSkip) const;

    // Friends:
    friend SquareMat operator*(double scalar, const SquareMat& mat);
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

} // namespace my_matrix

#endif // SQUAREMAT_HPP