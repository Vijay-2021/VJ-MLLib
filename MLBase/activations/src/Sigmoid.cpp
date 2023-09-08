#include "../includes/Sigmoid.h"

Matrix Sigmoid::computeGradient(const Matrix& upstream_gradient) {
    return computeSigmoid(upstream_gradient) *(Matrix::ones(upstream_gradient.width(), upstream_gradient.height()) - computeSigmoid(upstream_gradient));
}

Matrix Sigmoid::computeActivation(const Matrix& input) {
    return computeSigmoid(input);
}

Matrix Sigmoid::computeSigmoid(const Matrix& input) {
    Matrix output(input.width(), input.height());
    for (size_t row = 0; row < input.width(); row++) {
        for (size_t col = 0; col < input.height(); col ++ ) {
            double value = std::exp(-input.getElement(row, col));
            value = 1 / (1 + value);
            output.setElement(value, row, col);
        }
    }
    return output;
}

