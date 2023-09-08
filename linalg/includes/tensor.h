#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
using namespace std;
class Tensor { 
    public:
        Tensor();
        Tensor(size_t rows, size_t columns);
        Tensor(const Tensor& rhs);
        Tensor(double* new_data_array, size_t rows, size_t cols);
        static Tensor zeros(size_t rows, size_t columns);
        static Tensor ones(size_t rows, size_t columns);
        ~Tensor();

        void printTensor();

        //getters

        size_t height() const;
        size_t width() const;
        size_t elemCount() const;
        double* getRow(size_t row_idx) const;
        double* getCol(size_t col_idx) const;
        double getElement(size_t row_idx, size_t col_idx) const;

        //operations 

        void setRow(const Tensor& row_vector, size_t row_idx);
        void setCol(const Tensor& col_vector, size_t col_idx);
        void setRow(double* row_vector, size_t row_idx);
        void setCol(double* col_vector, size_t col_idx);
        void setElement(double value, size_t row_idx, size_t col_idx);
        Tensor TensorProd(const Tensor& other) const;
        double dotProd(double* vector_one, size_t vector_one_size, double* vector_two, size_t vector_two_size) const;

        Tensor transposeM(); // return a copy of the transpose of the Tensor
        void transpose(); // transpose the current Tensor
        //overloaded operators
        
        // Tensor-Tensor subtraction
        Tensor operator+(const Tensor& rhs) const;
        Tensor& operator+=(const Tensor& rhs);
        // Tensor-constant subtraction
        Tensor operator+(const double c) const;
        Tensor& operator+=(const double c);
        // Tensor-Tensor subtraction
        Tensor operator-(const Tensor& rhs) const;
        Tensor& operator-=(const Tensor& rhs);
        // Tensor-constant subtraction
        Tensor operator-(const double c) const;
        Tensor& operator-=(const double c);
        // Tensor element-wise multiplication
        Tensor operator*(const Tensor& rhs) const;
        Tensor& operator*=(const Tensor& rhs);
        // constant-Tensor multiplication
        Tensor operator*(const double c) const;
        Tensor& operator*=(const double c);
        // Tensor element-wise division
        Tensor operator/(const Tensor& rhs) const;
        Tensor& operator/=(const Tensor& rhs);
        // constant-Tensor division
        Tensor operator/(const double c) const;
        Tensor& operator/=(const double c);
        // typical Tensor multiplication
        Tensor operator%(const Tensor& rhs) const;
        Tensor& operator%=(const Tensor& rhs);
        // typical Tensor-vector multiplication
        // vector operator%(const vector& c); do this later when we create the vector class 
        // vector& operator%=(const vector& c); do this later when we create the vector class 

        // deep copy
        Tensor& operator=(const Tensor& rhs) ;
        bool operator==(const Tensor& rhs) const;
        bool operator!=(const Tensor& rhs) const;
        

        //utility functions: 

        void addRow(double* new_row, size_t row_size, size_t row_idx);
        void addCol(double* new_col, size_t col_size, size_t col_idx);

        void appendRow(double* new_row, size_t row_size);
        void appendCol(double* new_col, size_t col_size);
        
        double sum() const;
    private: 
        //private functions

        void deleteTensor();

        //will check if the right shape is broadcastable into the left shape 
        void checkBroadcastable(size_t left_rows, size_t left_cols, size_t right_rows, size_t right_cols); 

        //checks if the shape of a given Tensor matches the current shape
        bool checkShapesMatch(size_t lrows, size_t lcols, size_t rrows, size_t rcols) const; // to-do: make a shape class to handle this
        size_t getColIters(); // get the number of iterations over cols for the additional Tensor to the new(broadcasting)
        size_t getRowIters(); // get the number of iterations over the additional Tensor to the new Tensor
        
        //data members 
        
        size_t rows_; // at some posize_t we can make this array based for 3d and 4d matrices(or tensors), for convolutional neural networks
        size_t cols_;     
        size_t elem_count_;
        double* data_; 
};