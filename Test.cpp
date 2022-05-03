/**
 * @file Test.cpp
 * @author Elad Sezanayev
 * @brief Test cases for the matrix class
 * @date 2022-04
 */

#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace zich;
using namespace std;

TEST_CASE ("invalid inputs") {

    SUBCASE("invalid Matrix size for specific operators") {
        vector<double> vals1 = {2, 2, 2, 1, 1, 1, 3, 3, 3};
        Matrix mat1(vals1, 3, 3);
        vector<double> vals2 = {2, 2, 2, 1, 1, 1, 3, 3, 3, 4, 4, 4};
        Matrix mat2(vals2, 4, 3);
        bool none;
        CHECK_THROWS(mat1 + mat2);
        CHECK_THROWS(mat1 - mat2);
        CHECK_THROWS(mat1 * mat2);
        CHECK_THROWS(mat1 += mat2);
        CHECK_THROWS(mat1 -= mat2);
        CHECK_THROWS(mat1 *= mat2);
        CHECK_THROWS(none = mat1 == mat2); // the none is because clang-tidy yelling
        CHECK_THROWS(none = mat1 != mat2);
        CHECK_THROWS(none = mat1 > mat2);
        CHECK_THROWS(none = mat1 < mat2);
        CHECK_THROWS(none = mat1 <= mat2);
        CHECK_THROWS(none = mat1 >= mat2);
    }
}

TEST_CASE ("valid inputs") {

    SUBCASE("operators ERROR deducting") {
        vector<double> vals1 = {2, 2, 2, 1, 1, 1, 3, 3, 3};
        Matrix mat1(vals1, 3, 3);
        vector<double> vals2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        Matrix mat2(vals2, 3, 3);
        bool none;
        CHECK_NOTHROW(mat1 + mat2);
        CHECK_NOTHROW(mat1 - mat2);
        CHECK_NOTHROW(mat1 * mat2);
        CHECK_NOTHROW(mat1 += mat2);
        CHECK_NOTHROW(mat1 -= mat2);
        CHECK_NOTHROW(mat1 *= mat2);
        CHECK_NOTHROW(none = mat1 == mat2); // the none because tidy is yelling
        CHECK_NOTHROW(none = mat1 != mat2);
        CHECK_NOTHROW(none = mat1 > mat2);
        CHECK_NOTHROW(none = mat1 < mat2);
        CHECK_NOTHROW(none = mat1 <= mat2);
        CHECK_NOTHROW(none = mat1 >= mat2);
    }


    SUBCASE("Operators correctness check") {
        vector<double> vals1 = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
        Matrix mat1(vals1, 3, 3);
        vector<double> vals2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        Matrix mat2(vals2, 3, 3);

        CHECK(mat1 <= mat2);
        CHECK(mat2 >= mat1);
        CHECK(mat1 != mat2);
        CHECK(++mat1 == mat2);
        CHECK(mat1++ == mat2); // mat1 should fill with 3 after the postfix operator

        CHECK_NOTHROW(mat1 *= 2);
        CHECK_NOTHROW(mat2 *= 3);
        CHECK(mat1 == mat2); // they both fill with 6

        CHECK(mat1 * 3 == 3 * mat2);
        CHECK(mat1 + mat2 == mat2 + mat1);
        CHECK(mat1 - mat2 == mat2 - mat1); // both sides fill with 0

        CHECK_NOTHROW(mat1 += mat2);
        CHECK(mat1 == (mat2 * 2));

        CHECK_NOTHROW(mat1 -= mat2);
        CHECK(mat1 == mat2); // they both fill with 6
    }


    SUBCASE("Matrix multiplication testing"){
        vector<double> vals1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
        Matrix mat1(vals1, 4, 3);
        vector<double> vals2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        Matrix mat2(vals2, 3, 4);
        vector<double> ansval = {38, 44, 50, 56, 83, 98, 113, 128, 128, 152, 176, 200, 173, 206, 239, 272};
        Matrix ans(ansval, 4, 4);

        CHECK(ans == (mat1 * mat2));
        CHECK_NOTHROW(mat1 *= mat2);
        CHECK(ans == mat1);
    }
}