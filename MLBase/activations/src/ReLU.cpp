#include "../includes/ReLU.h"

Matrix ReLU::computeGradient(const Matrix& upstream_gradient) {
    Matrix output(upstream_gradient.height(), upstream_gradient.width());
    for (size_t row = 0; row < output.height(); row++) {
        for (size_t col = 0; col < output.width(); col++ ) {
            if (upstream_gradient.getElement(row, col) > 0) {
                output.setElement(1, row, col);
            }
        }
    }
    return output;
}

Matrix ReLU::computeActivation(const Matrix& input) {
    Matrix output = input;
    for (size_t row = 0; row < output.height(); row++) {
        for (size_t col = 0; col < output.width(); col++ ) {
            if (output.getElement(row, col) < 0) {
                output.setElement(0, row, col);
            }
        }
    }
    return output;
}