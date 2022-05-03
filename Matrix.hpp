/**
 * @file Test.cpp
 * @author Elad Sezanayev
 * @brief The declaration for Matrix class
 * @date 2022-04
 */


#include <iostream>
#include <vector>


namespace zich {
    class Matrix {
    private:
        size_t row, column;// row. column
        std::vector<double> mat;

        double count_all() const;
        size_t count_char(std::string str, char to_count);

    public:
        Matrix(std::vector<double> values, size_t row, size_t column);

        Matrix operator+(const Matrix &other) const;

        Matrix operator-(const Matrix &other) const;

        Matrix operator*(const Matrix &other) const;

        Matrix operator*(double num) const;

        Matrix operator-();

        Matrix operator+();

        Matrix &operator++(); // prefix adding

        Matrix operator++(int); // postfix adding

        Matrix &operator--(); // prefix sub

        Matrix operator--(int); // postfix sub

        Matrix &operator+=(const Matrix &other);

        Matrix &operator-=(const Matrix &other);

        Matrix &operator*=(const Matrix &other);

        Matrix &operator*=(double num);

        bool operator==(const Matrix &other) const;

        bool operator!=(const Matrix &other) const;

        bool operator>=(const Matrix &other) const;

        bool operator<=(const Matrix &other) const;

        bool operator<(const Matrix &other) const;

        bool operator>(const Matrix &other) const;

        friend Matrix operator*(int num, const Matrix &mat);

        friend std::istream &operator>>(std::istream &sin, Matrix &mat);

        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
    };

}
