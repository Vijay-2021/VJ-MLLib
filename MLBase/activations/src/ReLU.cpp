#include "../includes/ReLU.h"

Matrix ReLU::computeGradient(const Matrix& upstream_gradient) {
    Matrix output(upstream_gradient.width(), upstream_gradient.height());
    for (size_t row = 0; row < output.width(); row++) {
        for (size_t col = 0; col < output.height(); col++ ) {
            if (upstream_gradient.getElement(row, col) > 0) {
                output.setElement(1, row, col);
            }
        }
    }
    return output;
}

Matrix ReLU::computeActivation(const Matrix& input) {
    Matrix output = input;
    for (size_t row = 0; row < output.width(); row++) {
        for (size_t col = 0; col < output.height(); col++ ) {
            if (output.getElement(row, col) < 0) {
                output.setElement(0, row, col);
            }
        }
    }
    return output;
}