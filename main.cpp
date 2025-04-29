#include "SquareMat.hpp"
#include <iostream>

using namespace std;
using namespace my_matrix;

int main() {
    try {
        SquareMat A(2), B(2);

        A[0][0] = 1; A[0][1] = 2;
        A[1][0] = 3; A[1][1] = 4;

        B[0][0] = 5; B[0][1] = 6;
        B[1][0] = 7; B[1][1] = 8;

        cout << "Matrix A:\n" << A << endl;
        cout << "Matrix B:\n" << B << endl;

        cout << "A + B:\n" << (A + B) << endl;
        cout << "A - B:\n" << (A - B) << endl;
        cout << "A * B:\n" << (A * B) << endl;

        cout << "A * 2:\n" << (A * 2.0) << endl;
        cout << "2 * A:\n" << (2.0 * A) << endl;
        cout << "A / 2:\n" << (A / 2.0) << endl;

        cout << "Transpose of A (~A):\n" << (~A) << endl;
        cout << "Determinant of A (!A): " << !A << "\n" << endl;

        cout << "Element-wise A % B:\n" << (A % B) << endl;
        cout << "Modulo scalar A % 3:\n" << (A % 3) << endl;

        cout << "A squared (A^2):\n" << (A ^ 2) << endl;

        cout << "Comparisons:\n";
        cout << "A == B: " << (A == B) << endl;
        cout << "A != B: " << (A != B) << endl;
        cout << "A < B: " << (A < B) << endl;
        cout << "A <= B: " << (A <= B) << endl;
        cout << "A > B: " << (A > B) << endl;
        cout << "A >= B: " << (A >= B) << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}