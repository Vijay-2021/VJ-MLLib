#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
#include "../../losses/includes/losses.h"
#include "../../activations/includes/activations.h"

class Node {
    public: 
        Node();
        Node(double in_dim, double out_dim);
        Node(double in_dim, double out_dim, Losses loss_func); 
        Matrix compute_forward(const Matrix& input); 
        Matrix compute_backward(const Matrix& input); //take in the upstream gradient, compute local and downstream grad, return downstream grad
    private: 
        Losses loss_func_;
        Activation activation_;
        double in_dim_;
        double out_dim_; 
        Matrix weights_;       
        Matrix bias_;
};