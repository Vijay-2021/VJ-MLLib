#include "../includes/node.h"

Matrix Node::compute_forward(const Matrix& input) {
    Matrix forward_pass = (input % weights_) + bias_;
    Matrix output = activation_.computeActivation(forward_pass);
    return output;
}

Matrix Node::compute_backward(const Matrix& input) {
    return input;
}

