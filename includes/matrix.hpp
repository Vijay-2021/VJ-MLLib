#pragma once

#include <vector>

using namespace std;
class Matrix {

    vector<vector<double>> data;

    Matrix();
    Matrix(int rows, int columns);

    // matrix-matrix subtraction
    Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    // matrix-constant subtraction
    Matrix operator+(const Matrix& lhs, const double c);
    Matrix& operator+=(const double c);


    // matrix-matrix subtraction
    Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
    // matrix-constant subtraction
    Matrix operator-(const Matrix& lhs, const double c);
    Matrix& operator-=(const double c);


    // matrix element-wise multiplication
    Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
    // constant-matrix multiplication
    Matrix operator*(const Matrix& lhs, const double c);
    Matrix& operator*=(const double c);


    // matrix element-wise division
    Matrix operator/(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator/=(const Matrix& rhs);
    // constant-matrix division
    Matrix operator/(const Matrix& lhs, const double c);
    Matrix& operator/=(const double c);

    // typical matrix multiplication
    Matrix operator%(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator%=(const Matrix& rhs);
    // typical matrix-vector multiplication
    vector operator%(const Matrix& lhs, const vector& c);
    vector& operator%=(const vector& c);

    // deep copy
    Matrix& operator=(const Matrix& rhs);
};