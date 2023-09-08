#include "../includes/matrix.h"

// Static functions: 

Matrix Matrix::zeros(size_t rows, size_t columns) {
    double* data = new double[rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        data[i] = 0;
    }
    return Matrix(data, rows, columns);
}

Matrix Matrix::ones(size_t rows, size_t columns) {
    double* data = new double[rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        data[i] = 1;
    }
    return Matrix(data, rows, columns);
}


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
Matrix::Matrix(size_t rows, size_t columns): rows_(rows), cols_(columns), elem_count_(rows*columns) {
    data_ = new double[rows_ * cols_];
    for (size_t i = 0; i < elem_count_; i++) {
        data_[i] = 0;
    }
}
/**
* @param new_data_array the array of new entries to replace data with
* @param rows amount of rows in the new data array
* @param cols amount of columns in the new data array 
*/
Matrix::Matrix(double* new_data_array, size_t rows, size_t cols) {
    rows_ = rows;
    cols_ = cols;
    elem_count_ = rows_ * cols_;
    data_ = new double[elemCount()];
    for (size_t i = 0; i < elemCount(); i++) {
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
        for (size_t i = 0; i < elemCount(); i++) {
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
        for (size_t i =0; i < elemCount(); i++) {
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
    

    //print out in a more recognizable form
    std::cout << "matrix: " << std::endl;
    for (size_t i = 0; i < height(); i++) {
        for (size_t j = 0; j < width(); j++) {
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
    std::cout << "" << std::endl; // prsize_t a new line to put some space between matrix prints
}

//getters
double* Matrix::getRow(size_t row_idx) const {
    double* row = new double[width()];
    for (size_t i = 0; i < width(); i++) {
        row[i] = data_[width()*row_idx + i];
    }
    return row;
}
double* Matrix::getCol(size_t col_idx) const {
    double* col = new double[height()];
    for (size_t i = 0; i < height(); i++) {
        col[i] = data_[(width()*i) + col_idx];
    }
    return col;
}
double Matrix::getElement(size_t row_idx, size_t col_idx) const{
    if (row_idx > rows_ - 1 || col_idx > cols_ - 1) {
        throw std::invalid_argument("pass valid row and col index");
    }
    return data_[row_idx*width() + col_idx];
}
size_t Matrix::height() const {return rows_;}
size_t Matrix::width() const {return cols_;}
size_t Matrix::elemCount() const {return elem_count_;}
//setters

void Matrix::setRow(const Matrix& row_vector, size_t row_idx) {
    if (row_vector.width() == width() && row_vector.height() == 1) {

    }
}
void Matrix::setCol(const Matrix& col_vector, size_t col_idx) {}
void Matrix::setRow(double* row_vector, size_t row_idx) {
    for (size_t i = 0; i < width(); i++) {
        data_[width()*row_idx + i] = row_vector[i];
    }
}
void Matrix::setCol(double* col_vector, size_t col_idx) {
    for (size_t i = 0; i < height(); i++) {
        data_[(width()*i) + col_idx] = col_vector[i];
    }
}
void Matrix::setElement(double value, size_t row_idx, size_t col_idx) {
    if (row_idx > rows_ - 1 || col_idx > cols_ - 1) {
        throw std::invalid_argument("pass valid row and col index");
    }
    data_[row_idx*width() + col_idx] = value;
}

// extras

double Matrix::dotProd(double* vector_one, size_t vector_one_size, double* vector_two, size_t vector_two_size) const{
    if (vector_one_size != vector_two_size) {
        throw std::invalid_argument("the vectors must have the same size");
    }
    double output = 0; 
    for (size_t index = 0; index < vector_one_size; index++) {
        output += vector_one[index]*vector_two[index];
    } 
    return output;
}

//Matrix Matrix Operations: 

Matrix Matrix::matrixProd(const Matrix& other) const{
    if (other.rows_ != cols_) {
        throw std::invalid_argument("the number of rows in the other matrix must equal the number of columns in the current matrix");
    }
    Matrix new_matrix(rows_, other.cols_);
    for (size_t row = 0; row < rows_; row++) {
        for (size_t col = 0; col < other.cols_; col++) {
            double* matrix_row = getRow(row);
            double* column = other.getCol(col);
            double output = dotProd(matrix_row, cols_, column, other.rows_);
            new_matrix.setElement(output, row, col);
            delete[] matrix_row;
            delete[] column;
        }
    }
    return new_matrix;
}

//return the transpose of the current matrix
Matrix Matrix::transposeM() {
    Matrix new_matrix(cols_, rows_);
    for (size_t i = 0; i < cols_; i++) {
        double* column = getCol(i);
        new_matrix.setRow(column, i);
        delete[] column;
    }
    return new_matrix;
} 
//transpose the current matrix
void Matrix::transpose() {
    Matrix temp = transposeM();
    delete[] data_;
    elem_count_ = temp.elem_count_;
    data_ = new double[elem_count_];
    if (temp.elemCount() > 0) {
        for (size_t i =0; i < elemCount(); i++) {
            data_[i] = temp.data_[i];
        }
    } else {
        data_ = nullptr;
    }
    rows_ = temp.rows_;
    cols_ = temp.cols_;
} // transpose the current matrix
//overloaded operators


// matrix-matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] + rhs.data_[i*width() + j];
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator+=(const Matrix& rhs) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] += rhs.data_[i*width() + j];
        }
    }
    return *this;
}
// matrix-constant addition
Matrix Matrix::operator+(const double c) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] + c;
        }
    }
     return Matrix(output, rows_, cols_);
}
Matrix& Matrix::operator+=(const double c) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] += c;
        }
    }
    return *this;
}


// matrix-matrix subtraction
Matrix Matrix::operator-(const Matrix& rhs) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] - rhs.data_[i*width() + j];
        }
    }
    return Matrix(output, rows_, cols_);
}
Matrix& Matrix::operator-=(const Matrix& rhs) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] -= rhs.data_[i*width() + j];
        }
    }
    return *this;
}
// matrix-constant subtraction
Matrix Matrix::operator-(const double c) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] - c;
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator-=(const double c) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] -= c;
        }
    }
    return *this;
}


// matrix element-wise multiplication
Matrix Matrix::operator*(const Matrix& rhs) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] * rhs.data_[i*width() + j];
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator*=(const Matrix& rhs) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] *= rhs.data_[i*width() + j];
        }
    }
    return *this;
}
// constant-matrix multiplication
Matrix Matrix::operator*(const double c) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] * c;
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator*=(const double c) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] *= c;
        }
    }
    return *this;
}


// matrix element-wise division
Matrix Matrix::operator/(const Matrix& rhs) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] / rhs.data_[i*width() + j];
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator/=(const Matrix& rhs) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] /= rhs.data_[i*width() + j];
        }
    }
    return *this;
}
// constant-matrix division
Matrix Matrix::operator/(const double c) const{
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = data_[i*width() + j] / c;
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}
Matrix& Matrix::operator/=(const double c) {
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j ++) {
            data_[i*width() + j] /= c;
        }
    }
    return *this;
}

// typical matrix multiplication
Matrix Matrix::operator%(const Matrix& rhs) const{
    return matrixProd(rhs);
}
Matrix& Matrix::operator%=(const Matrix& rhs) {
    Matrix output = matrixProd(rhs);
    delete[] data_;
    rows_ = output.rows_;
    cols_ = output.cols_;
    elem_count_ = output.elem_count_;
    if (elemCount() > 0) {
        data_ = new double[elemCount()];
        for (size_t i = 0; i < elemCount(); i++) {
            data_[i] = output.data_[i];
        }
    } else {
        data_ = nullptr; // define an empty matrix as nullptr with rows and cols = 0
    }
    return *this;
}

Matrix Matrix::operator^(const Matrix& rhs) const {
    double* output = new double[rows_*cols_];
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            output[i*width() + j] = std::pow(data_[i*width() + j], rhs.data_[i*width() + j]);
        }
    }
    Matrix out(output, rows_, cols_);
    delete[] output; 
    return out;
}

Matrix& Matrix::operator^=(const Matrix& rhs) {

    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            data_[i*width() + j] = std::pow(data_[i*width() + j], rhs.data_[i*width() + j]);
        }
    }
    return *this;
}

// typical matrix-vector multiplication
//vector operator%(const vector& c); do this later when we create the vector class 
//vector& operator%=(const vector& c); do this later when we create the vector class 

bool Matrix::checkShapesMatch(size_t lrows, size_t lcols, size_t rrows, size_t rcols) const{
    return (lcols == rcols && lrows == rrows);
}

bool Matrix::operator==(const Matrix& rhs) const {
    if (!checkShapesMatch(rows_, cols_, rhs.rows_, rhs.cols_)) {
        return false;
    }
    for (size_t i = 0; i < elemCount(); i++) {
        if (rhs.data_[i] != data_[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const {
    return !(*this == rhs);
}



void Matrix::addRow(double* new_row, size_t row_size, size_t row_idx) {
    if (row_size != width()) {
        throw std::invalid_argument("row size must match width");
    }
    double* new_data = new double[elem_count_ + row_size];
    for (size_t i = 0; i < row_idx * width(); i++) {
        new_data[i] = data_[i];
    }
    for (size_t i = (row_idx * width()); i < (row_idx + 1)*width(); i++) {
        new_data[i] = new_row[i - (row_idx*width())];
    }
    for (size_t i = row_idx*width(); i < elem_count_; i++) {
        new_data[i + width()] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    rows_ += 1;
    elem_count_ += cols_;
}
void Matrix::addCol(double* new_col, size_t col_size, size_t col_idx) {
    if (col_size != height()) {
        throw std::invalid_argument("the column size must be equal to the height");
    }
    double* new_data = new double[elem_count_ + col_size];
    for (size_t col = 0; col < cols_ + 1; col++) {
        if (col < col_idx) {
            for (size_t row = 0; row < rows_; row++) {
                size_t idx1 = (width()*row) + col;
                size_t idx2 = ((width() + 1)*row) + col;
                new_data[idx2] = data_[idx1];
            }
        } else if (col == col_idx) {
            for (size_t row = 0; row < rows_; row++) {
                size_t idx = ((width() + 1)*row) + col;
                new_data[idx] = new_col[row];
            }
        } else {
            for (size_t row = 0; row < rows_; row++) {
                size_t idx1 = (width()*row) + col - 1;
                size_t idx2 = ((width() + 1)*row) + col;
                new_data[idx2] = data_[idx1];
            }  
        }
    }
    delete[] data_;
    data_ = new_data;
    cols_ += 1; 
    elem_count_ += rows_;
}

void Matrix::appendRow(double* new_row, size_t row_size) {
    addRow(new_row, row_size, rows_);
}
void Matrix::appendCol(double* new_col, size_t col_size) {
    addCol(new_col, col_size, cols_);
}

double Matrix::sum() const{
    double sum = 0;
    for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
            sum += data_[i * width() + j];
        }
    }
    return sum;
}

bool Matrix::approxEquals(double precision, const Matrix& rhs) {
    if (!checkShapesMatch(rows_, cols_, rhs.rows_, rhs.cols_)) {
        return false;
    }
    double precision_constant = std::pow(10, -precision);
    for (size_t i = 0; i < elemCount(); i++) {
        double difference = std::abs(rhs.data_[i] - data_[i]);
        if (difference > precision_constant) { // we do greater than so a precision of zero just tests for equality
            return false;
        }
    }
    return true;
}