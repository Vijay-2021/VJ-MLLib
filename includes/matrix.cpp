#include "matrix.hpp"

//Constructors: 

Matrix::Matrix() {
    // do nothing for now
    data_ = nullptr;
    rows_ = 0;
    cols_ = 0;
}

/**
* Initializes a matrix of zeros
*/
Matrix::Matrix(int rows, int columns): rows_(rows), cols_(columns), elem_count_(rows*columns) {
    data_ = new double[rows_ * cols_];
    for (int i = 0; i < elem_count_; i++) {
        data_[i] = 0;
    }
}
/**
* @param new_data_array the array of new entries to replace data with
* @param rows amount of rows in the new data array
* @param cols amount of columns in the new data array 
*/
Matrix::Matrix(double* new_data_array, int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    elem_count_ = rows_ * cols_;
    data_ = new double[elemCount()];
    for (int i = 0; i < elemCount(); i++) {
        data_[i] = new_data_array[i];
    }
}

//rule of three functions: 

Matrix::Matrix(const Matrix& rhs) {
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    elem_count_ = rhs.elem_count_;
    if (elemCount() > 0) {
        data_ = new double[elemCount()];
        for (int i = 0; i < elemCount(); i++) {
            data_[i] = rhs.data_[i];
        }
    } else {
        data_ = nullptr; // define an empty matrix as nullptr with rows and cols = 0
    }

}

// deep copy
Matrix& Matrix::operator=(const Matrix& rhs) {
    if (&rhs == this) return *this;
    deleteMatrix();
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    elem_count_ = rhs.elem_count_;
    data_ = new double[elem_count_];
    if (rhs.elemCount() > 0) {
        for (int i =0; i < elemCount(); i++) {
            data_[i] = rhs.data_[i];
        }
    } else {
        data_ = nullptr;
    }
    return *this;
}

Matrix::~Matrix() {
    deleteMatrix();
}

//utility functions
void Matrix::deleteMatrix() {
    delete[] data_;
    data_ = nullptr;
    rows_ = 0; // maybe refactor to delete matrix at some point
    cols_ = 0; 
}

void Matrix::printMatrix() {
    //print out all the entries to confirm that data is being stored in memory correctly 
    std::cout << "" << std::endl;// print out a new line to get some space between prints
    std::cout << "entries: " << std::endl;
    for (int i = 0; i < elemCount(); i++) {
        std::cout << data_[i] << ",";
    }

    //print out in a more recognizable form
    std::cout << "" << std::endl;
    std::cout << "matrix: " << std::endl;
    for (int i = 0; i < height(); i++) {
        for (int j = 0; j < width(); j++) {
            if (j == 0) {
                std::cout << "[";
            }
            if (j != width() - 1) {
                std::cout << data_[(width() * i) + j] << ","; 
            } else {
                std::cout << data_[(width() * i) + j] << "]" << std::endl;
            }
        }
    }
    std::cout << "" << std::endl; // print a new line to put some space between matrix prints
}

//getters
double* Matrix::getRow(int row_idx) const {
    double output[width()];
    for (int i = 0; i < width(); i++) {
        output[i] = data_[width()*row_idx + i];
    }
}
double* Matrix::getCol(int col_idx) const {
    double output[height()];
    for (int i = 0; i < height(); i++) {
        output[i] = data_[(width()*i) + col_idx];
    }
}
double Matrix::getElement(int row_idx, int col_idx) const{
    if (row_idx > rows_ - 1 || col_idx > cols_ - 1 || row_idx < 0 || col_idx < 0) {
        throw std::invalid_argument("pass valid row and col index");
    }
    return data_[row_idx*width() + col_idx];
}
int Matrix::height() const {return rows_;}
int Matrix::width() const {return cols_;}
int Matrix::elemCount() const {return elem_count_;}
//setters

void Matrix::setRow(const Matrix& row_vector, int row_idx) {
    if (row_vector.width() == width() && row_vector.height() == 1) {

    }
}
void Matrix::setCol(const Matrix& col_vector, int col_idx) {}
void Matrix::setRow(double* row_vector, int row_idx) {}
void Matrix::setCol(double* col_vector, int col_idx) {}
void Matrix::setElement(double value, int row_idx, int col_idx) {
    if (row_idx > rows_ - 1 || col_idx > cols_ - 1 || row_idx < 0 || col_idx < 0) {
        throw std::invalid_argument("pass valid row and col index");
    }
    data_[row_idx*width() + col_idx] = value;
}


//return the transpose of the current matrix
Matrix Matrix::transposeM() {
    return Matrix(rows_, cols_);
} 
//transpose the current matrix
void Matrix::transpose() {

} // transpose the current matrix
//overloaded operators



// matrix-matrix addition
Matrix Matrix::operator+(const Matrix& rhs){
    double output[rows_*cols_];
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] + rhs.data_[i*width() + j];
        }
    }
    return Matrix(output, rows_, cols_);
}
Matrix& Matrix::operator+=(const Matrix& rhs){
    return *this;
}
// matrix-constant addition
Matrix Matrix::operator+(const double c){
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator+=(const double c){
    return *this;
}


// matrix-matrix subtraction
Matrix Matrix::operator-(const Matrix& rhs){
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator-=(const Matrix& rhs){
    return *this;
}
// matrix-constant subtraction
Matrix Matrix::operator-(const double c){
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator-=(const double c){
    return *this;
}


// matrix element-wise multiplication
Matrix Matrix::operator*(const Matrix& rhs) {
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator*=(const Matrix& rhs) {
    return *this;
}
// constant-matrix multiplication
Matrix Matrix::operator*(const double c) {
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator*=(const double c) {
    return *this;
}


// matrix element-wise division
Matrix Matrix::operator/(const Matrix& rhs) {
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator/=(const Matrix& rhs) {
    return *this;
}
// constant-matrix division
Matrix Matrix::operator/(const double c) {
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator/=(const double c) {
    return *this;
}

// typical matrix multiplication
Matrix Matrix::operator%(const Matrix& rhs) {
     return Matrix(rows_, cols_);
}
Matrix& Matrix::operator%=(const Matrix& rhs) {
    return *this;
}
// typical matrix-vector multiplication
//vector operator%(const vector& c); do this later when we create the vector class 
//vector& operator%=(const vector& c); do this later when we create the vector class 

bool Matrix::checkShapesMatch(int lrows, int lcols, int rrows, int rcols) const{
    return (lcols == rcols && lrows == rrows);
}

bool Matrix::operator==(const Matrix& rhs) const {
    if (!checkShapesMatch(rows_, cols_, rhs.rows_, rhs.cols_)) {
        return false;
    }
    for (int i = 0; i < elemCount(); i++) {
        if (rhs.data_[i] != data_[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const {
    return !(*this == rhs);
}