#include <iostream>
#include "Matrix.hpp"

namespace zich {
    Matrix::Matrix(std::vector<double> values, int r, int c) {};

    Matrix Matrix::operator+(const Matrix &other) const { return other; }

    Matrix Matrix::operator-(const Matrix &other) const { return other; }

    Matrix Matrix::operator*(const Matrix &other) const { return other; }

    Matrix Matrix::operator*(double num) const { return *this; }

    Matrix Matrix::operator-() { return *this; }

    Matrix &Matrix::operator++() { return *this; }

    Matrix Matrix::operator++(int) { return *this; }

    Matrix &Matrix::operator--() { return *this; }

    Matrix Matrix::operator--(int) { return *this; }

    void Matrix::operator+=(const Matrix &other) {}

    void Matrix::operator-=(const Matrix &other) {}

    void Matrix::operator*=(const Matrix &other) {}

    void Matrix::operator*=(double num) {}

    bool Matrix::operator==(const Matrix &other) const { return false; }

    bool Matrix::operator!=(const Matrix &other) const { return false; }

    bool Matrix::operator>=(const Matrix &other) const { return false; }

    bool Matrix::operator<=(const Matrix &other) const { return false; }

    bool Matrix::operator<(const Matrix &other) const { return false; }

    bool Matrix::operator>(const Matrix &other) const { return false; }

    Matrix operator*(int num, Matrix m) { return m; }

    std::istream &operator>>(std::istream &in, Matrix &m) { return in; }

    std::ostream &operator<<(std::ostream &out, const Matrix &m) { return out; }
}
