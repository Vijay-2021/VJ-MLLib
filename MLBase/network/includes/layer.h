#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
#include "../../losses/includes/losses.h"
#include "../../activations/includes/activations.h"
#include "node.h"

//perhaps at some point we will make this a little more abstract to account for CNNs and attention 
class Layer {
    public: 
        Layer();
        Layer(size_t input_dim, size_t output_dim);
        Layer(const Matrix& input_weights, const Matrix& bias_weights, const Activation& activation);
        Layer(size_t input_dim, size_t output_dim, const Activation& activation);
        Layer(const Layer& rhs);
        Layer& operator=(const Layer& input_layer);
        void setWeights(const Matrix& input_weights);
        void setBias(const Matrix& input_bias);
        void setActivation(const Activation& activation);
        
        Matrix computeBackward(const Matrix& upstream_gradient);
        Matrix computeForward(const Matrix& input); 
        Matrix updateForward(const Matrix& upstream_gradient);
        Matrix updateBackward(const Matrix& upstream_gradient); // this actually updates weights and biases 
        
        Matrix getWeights() const;
        Matrix getBias() const;
        Activation getActivation() const;
    private: 
        Activation activation_;
        Matrix weights_;
        Matrix bias_;
        Matrix last_input_; 
        Matrix weights_gradient_; //learning rate parameter is not controlled here so we can only store the weights and bias gradient 
        Matrix bias_gradient_; 
        size_t input_dim_;
        size_t output_dim_;

};