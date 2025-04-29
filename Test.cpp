// test.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace my_matrix;

TEST_CASE("Matrix construction and element access") {
    CHECK_THROWS(SquareMat(0));
    SquareMat m(2);
    m[0][0] = 1.0; m[0][1] = 2.0;
    m[1][0] = 3.0; m[1][1] = 4.0;
    CHECK(m[0][0] == doctest::Approx(1.0));
    CHECK_THROWS(m[2][0]);
    CHECK_THROWS(m[-1][0]);
}

TEST_CASE("Matrix addition, subtraction and mismatch handling") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;
    SquareMat sum = a + b;
    SquareMat diff = a - b;
    CHECK(sum[1][1] == doctest::Approx(12));
    CHECK(diff[0][0] == doctest::Approx(-4));

    SquareMat c(3);
    CHECK_THROWS(a + c);
    CHECK_THROWS(a - c);
}

TEST_CASE("Unary minus and scalar operations") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = -2; a[1][0] = -3; a[1][1] = 4;
    SquareMat neg = -a;
    CHECK(neg[0][1] == doctest::Approx(2));

    SquareMat scaled = a * 2;
    CHECK(scaled[1][1] == doctest::Approx(8));
    CHECK_THROWS(a / 0);
    SquareMat divided = a / 2;
    CHECK(divided[1][1] == doctest::Approx(2));

    SquareMat scaled2 = 3.0 * a;
    CHECK(scaled2[0][0] == doctest::Approx(3));
}

TEST_CASE("Matrix multiplication and power") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    SquareMat result = a * a;
    CHECK(result[0][0] == doctest::Approx(7));
    CHECK(result[1][1] == doctest::Approx(22));

    SquareMat power = a ^ 2;
    CHECK(power[1][0] == doctest::Approx(15));
    CHECK_THROWS(a ^ -1);
}

TEST_CASE("Modulo operations") {
    SquareMat a(2);
    a[0][0] = 10; a[0][1] = 7; a[1][0] = 4; a[1][1] = 3;
    SquareMat b(2);
    b[0][0] = 3; b[0][1] = 2; b[1][0] = 2; b[1][1] = 3;
    SquareMat elemwise = a % b;
    CHECK(elemwise[0][1] == doctest::Approx(14));

    CHECK_THROWS(a % 0);
    SquareMat scalarMod = a % 3;
    CHECK(scalarMod[0][0] == doctest::Approx(1));
}

TEST_CASE("Transpose and determinant") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    SquareMat t = ~a;
    CHECK(t[0][1] == doctest::Approx(3));
    CHECK(!a == doctest::Approx(-2));

    SquareMat s(1);
    s[0][0] = 42;
    CHECK(!s == doctest::Approx(42));
}

TEST_CASE("Increment and decrement") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 1;
    ++a;
    CHECK(a[0][0] == doctest::Approx(2));
    SquareMat pre = a--;
    CHECK(pre[0][0] == 2);
    CHECK(a[0][0] == doctest::Approx(1));
}

TEST_CASE("Compound assignments and comparison") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    SquareMat temp = a;
    temp += b;
    CHECK(temp[1][1] == doctest::Approx(12));
    temp -= b;
    CHECK(temp[1][1] == doctest::Approx(4));
    temp *= b;
    CHECK(temp[1][1] == doctest::Approx(50));
    temp %= b;
    CHECK(temp[0][0] == doctest::Approx(95));
    temp %= 5;
    CHECK(temp[0][0] == doctest::Approx(0));
    temp /= 2.0;
    CHECK(temp[1][1] == doctest::Approx(0));

    CHECK(a == a);
    CHECK(a != b);
    CHECK(b > a);
    CHECK(a < b);
    CHECK(a <= a);
    CHECK(b >= a);
}

TEST_CASE("Minor extraction and sum helper") {
    SquareMat m(3);
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
    m[1][0] = 0; m[1][1] = 4; m[1][2] = 5;
    m[2][0] = 1; m[2][1] = 0; m[2][2] = 6;

    SquareMat minor = m.extractMinor(0, 0);
    CHECK(minor[0][0] == doctest::Approx(4));
    CHECK(minor[1][1] == doctest::Approx(6));
    CHECK(m.sum() == doctest::Approx(22));
}
