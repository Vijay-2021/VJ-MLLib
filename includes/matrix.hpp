#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>

using namespace std;
class Matrix { 
    public:
        Matrix();
        Matrix(int rows, int columns);
        Matrix(const Matrix& rhs);
        Matrix(double* new_data_array, int rows, int cols);
        ~Matrix();

        void printMatrix();

        //getters

        int height() const;
        int width() const;
        int elemCount() const;
        double* getRow(int row_idx) const;
        double* getCol(int col_idx) const;
        double getElement(int row_idx, int col_idx) const;

        //operations 

        void setRow(const Matrix& row_vector, int row_idx);
        void setCol(const Matrix& col_vector, int col_idx);
        void setRow(double* row_vector, int row_idx);
        void setCol(double* col_vector, int col_idx);
        void setElement(double value, int row_idx, int col_idx);

        Matrix transposeM(); // return a copy of the transpose of the matrix
        void transpose(); // transpose the current matrix
        //overloaded operators
        
        // matrix-matrix subtraction
        Matrix operator+(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);
        // matrix-constant subtraction
        Matrix operator+(const double c);
        Matrix& operator+=(const double c);
        // matrix-matrix subtraction
        Matrix operator-(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        // matrix-constant subtraction
        Matrix operator-(const double c);
        Matrix& operator-=(const double c);
        // matrix element-wise multiplication
        Matrix operator*(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);
        // constant-matrix multiplication
        Matrix operator*(const double c);
        Matrix& operator*=(const double c);
        // matrix element-wise division
        Matrix operator/(const Matrix& rhs);
        Matrix& operator/=(const Matrix& rhs);
        // constant-matrix division
        Matrix operator/(const double c);
        Matrix& operator/=(const double c);
        // typical matrix multiplication
        Matrix operator%(const Matrix& rhs);
        Matrix& operator%=(const Matrix& rhs);
        // typical matrix-vector multiplication
        // vector operator%(const vector& c); do this later when we create the vector class 
        // vector& operator%=(const vector& c); do this later when we create the vector class 

        // deep copy
        Matrix& operator=(const Matrix& rhs);
        bool operator==(const Matrix& rhs) const;
        bool operator!=(const Matrix& rhs) const;
        double* data_; 
    private: 
        //private functions

        void deleteMatrix();

        //will check if the right shape is broadcastable into the left shape 
        void checkBroadcastable(int left_rows, int left_cols, int right_rows, int right_cols); 

        //checks if the shape of a given matrix matches the current shape
        bool checkShapesMatch(int lrows, int lcols, int rrows, int rcols) const; // to-do: make a shape class to handle this
        int getColIters(); // get the number of iterations over cols for the additional matrix to the new(broadcasting)
        int getRowIters(); // get the number of iterations over the additional matrix to the new matrix
        
        //data members 
        
        int rows_; // at some point we can make this array based for 3d and 4d matrices(or tensors), for convolutional neural networks
        int cols_;     
        int elem_count_;
        
};