#include <iostream>
#include <vector>


namespace zich {
    class Matrix {
    private:
        int r, c;// row. column
        std::vector<double> mat;

    public:
        Matrix(std::vector<double> values, int r, int c);

        Matrix operator+(const Matrix &other) const;

        Matrix operator-(const Matrix &other) const;

        Matrix operator*(const Matrix &other) const;

        Matrix operator*(double num) const;

        Matrix operator-();

        Matrix &operator++(); // prefix adding

        Matrix operator++(int); // postfix adding

        Matrix &operator--(); // prefix sub

        Matrix operator--(int); // postfix sub

        void operator+=(const Matrix &other);

        void operator-=(const Matrix &other);

        void operator*=(const Matrix &other);

        void operator*=(double num);

        bool operator==(const Matrix &other) const;

        bool operator!=(const Matrix &other) const;

        bool operator>=(const Matrix &other) const;

        bool operator<=(const Matrix &other) const;

        bool operator<(const Matrix &other) const;

        bool operator>(const Matrix &other) const;

        friend Matrix operator*(int num, Matrix m);

        friend std::istream &operator>>(std::istream &in, Matrix &m);

        friend std::ostream &operator<<(std::ostream &out, const Matrix &m);
    };

}
