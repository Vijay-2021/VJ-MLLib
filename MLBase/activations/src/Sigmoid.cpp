#include "../includes/Sigmoid.h"

Matrix Sigmoid::computeGradient(const Matrix& upstream_gradient) {
    return computeSigmoid(upstream_gradient) *(Matrix::ones(upstream_gradient.height(), upstream_gradient.width()) - computeSigmoid(upstream_gradient));
}

Matrix Sigmoid::computeActivation(const Matrix& input) {
    return computeSigmoid(input);
}

Matrix Sigmoid::computeSigmoid(const Matrix& input) {
    Matrix output(input.height(), input.width());
    for (size_t row = 0; row < input.height(); row++) {
        for (size_t col = 0; col < input.width(); col ++ ) {
            double value = std::exp(-input.getElement(row, col));
            value = 1 / (1 + value);
            output.setElement(value, row, col);
            
        }
    }
    return output;
}

