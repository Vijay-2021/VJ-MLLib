#include "../includes/layer.h"

Layer::Layer() {
    input_dim_ = 1;
    output_dim_= 1;
    weights_ = Matrix::zeros(1,1);
    bias_ = Matrix::zeros(1,1);     
}
Layer::Layer(size_t input_dim, size_t output_dim) {
    weights_ = Matrix::zeros(input_dim, output_dim);
    bias_ = Matrix::zeros(output_dim, 1);
    input_dim_ = input_dim;
    output_dim_ = output_dim;
}
Layer::Layer(const Matrix& input_weights, const Matrix& bias_weights, const Activation& activation) {
    weights_ = input_weights;
    bias_ = bias_weights;
    activation_ = activation;
    input_dim_ = input_weights.height();
    output_dim_ = input_weights.width();
}
Layer::Layer(size_t input_dim, size_t output_dim, const Activation& activation) {
    weights_ = Matrix::zeros(input_dim, output_dim);
    bias_ = Matrix::zeros(output_dim, 1);
    input_dim_ = input_dim;
    output_dim_ = output_dim;
    activation_ = activation; 
}

Layer::Layer(const Layer& input_layer) {
    weights_ = input_layer.getWeights();
    bias_ = input_layer.getBias();
    input_dim_ = weights_.height();
    output_dim_ = weights_.width();
    activation_ = input_layer.getActivation();
}
Matrix Layer::getWeights() const {
    return weights_;
}

Matrix Layer::getBias() const {
    return bias_;
}
Activation Layer::getActivation() const {
    return activation_;
}
void Layer::setWeights(const Matrix& input_weights) {
    weights_ = input_weights;
}
void Layer::setBias(const Matrix& input_bias) {
    bias_ = input_bias;
}
void Layer::setActivation(const Activation& activation) {
    activation_ = activation;
}

Matrix Layer::computeForward(const Matrix& input) {
    Matrix linear = (weights_ % input) + bias_;
    Matrix output = activation_.computeActivation(linear);
    return output;
}

Matrix Layer::computeBackward(const Matrix& upstream_gradient) {
    return (activation_.computeGradient(upstream_gradient) % weights_.transposeM()); 

}

Matrix Layer::updateForward(const Matrix& input) {
    last_input_ = input;
    Matrix linear = (weights_ % input) + bias_;
    Matrix output = activation_.computeActivation(linear);
    return output;
}

Matrix Layer::updateBackward(const Matrix& upstream_gradient) {
    Matrix activation_gradient = activation_.computeActivation(upstream_gradient);
    bias_gradient_ = activation_gradient;
    weights_gradient_ = last_input_.transposeM() % activation_gradient;
    return activation_gradient % weights_.transposeM();
}