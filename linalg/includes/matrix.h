#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include <cmath> 

using namespace std;
class Matrix { 
    public:
        Matrix();
        Matrix(size_t rows, size_t columns);
        Matrix(const Matrix& rhs);
        Matrix(double* new_data_array, size_t rows, size_t cols);
        static Matrix zeros(size_t rows, size_t columns);
        static Matrix ones(size_t rows, size_t columns);
        static Matrix random(size_t rows, size_t columns);
        
        ~Matrix();

        void printMatrix();

        //getters

        size_t height() const;
        size_t width() const;
        size_t elemCount() const;
        double* getRow(size_t row_idx) const;
        double* getCol(size_t col_idx) const;
        double getElement(size_t row_idx, size_t col_idx) const;

        //operations 

        void setRow(const Matrix& row_vector, size_t row_idx);
        void setCol(const Matrix& col_vector, size_t col_idx);
        void setRow(double* row_vector, size_t row_idx);
        void setCol(double* col_vector, size_t col_idx);
        void setElement(double value, size_t row_idx, size_t col_idx);
        Matrix matrixProd(const Matrix& other) const;
        double dotProd(double* vector_one, size_t vector_one_size, double* vector_two, size_t vector_two_size) const;

        Matrix transposeM(); // return a copy of the transpose of the matrix
        void transpose(); // transpose the current matrix
        //overloaded operators
        
        // matrix-matrix subtraction
        Matrix operator+(const Matrix& rhs) const;
        Matrix& operator+=(const Matrix& rhs);
        // matrix-constant subtraction
        Matrix operator+(const double c) const;
        Matrix& operator+=(const double c);
        // matrix-matrix subtraction
        Matrix operator-(const Matrix& rhs) const;
        Matrix& operator-=(const Matrix& rhs);
        // matrix-constant subtraction
        Matrix operator-(const double c) const;
        Matrix& operator-=(const double c);
        // matrix element-wise multiplication
        Matrix operator*(const Matrix& rhs) const;
        Matrix& operator*=(const Matrix& rhs);
        // constant-matrix multiplication
        Matrix operator*(const double c) const;
        Matrix& operator*=(const double c);
        // matrix element-wise division
        Matrix operator/(const Matrix& rhs) const;
        Matrix& operator/=(const Matrix& rhs);
        // constant-matrix division
        Matrix operator/(const double c) const;
        Matrix& operator/=(const double c);
        // typical matrix multiplication
        Matrix operator%(const Matrix& rhs) const;
        Matrix& operator%=(const Matrix& rhs);
        // typical matrix-vector multiplication
        // vector operator%(const vector& c); do this later when we create the vector class 
        // vector& operator%=(const vector& c); do this later when we create the vector class 

        // deep copy
        Matrix& operator=(const Matrix& rhs) ;
        bool operator==(const Matrix& rhs) const;
        bool operator!=(const Matrix& rhs) const;
        
        Matrix operator^(const Matrix& rhs) const;
        Matrix& operator^=(const Matrix& rhs);
        
        //utility functions: 

        void addRow(double* new_row, size_t row_size, size_t row_idx);
        void addCol(double* new_col, size_t col_size, size_t col_idx);

        void appendRow(double* new_row, size_t row_size);
        void appendCol(double* new_col, size_t col_size);
        
        double sum() const;
        bool approxEquals(double precision, const Matrix& rhs);

    private: 
        //private functions

        void deleteMatrix();

        //will check if the right shape is broadcastable into the left shape 
        void checkBroadcastable(size_t left_rows, size_t left_cols, size_t right_rows, size_t right_cols); 

        //checks if the shape of a given matrix matches the current shape
        bool checkShapesMatch(size_t lrows, size_t lcols, size_t rrows, size_t rcols) const; // to-do: make a shape class to handle this
        size_t getColIters(); // get the number of iterations over cols for the additional matrix to the new(broadcasting)
        size_t getRowIters(); // get the number of iterations over the additional matrix to the new matrix
        
        //data members 
        
        size_t rows_; // at some posize_t we can make this array based for 3d and 4d matrices(or tensors), for convolutional neural networks
        size_t cols_;     
        size_t elem_count_;
        double* data_; 
};