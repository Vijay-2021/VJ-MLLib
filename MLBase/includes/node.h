#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../linalg/includes/matrix.h"
#include "losses.h"

class Node {
    public: 
        Node();
        Node(double in_dim, double out_dim);
        Node(double in_dim, double out_dim, Losses loss_func); 
        Matrix compute_forward(const Matrix& input);

    private: 
        Losses loss_func_;
        double in_dim_;
        double out_dim_; 
        Matrix weights_; 
};