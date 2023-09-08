#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include <cmath>
#include "../../../linalg/includes/matrix.h"
#include "activations.h"
using namespace std;

class Sigmoid : public Activation{
    public: 
        Matrix computeGradient(const Matrix& upstream_gradient) override;
        Matrix computeActivation(const Matrix& input) override;
        ~Sigmoid() {}; 
    private: 
        Matrix computeSigmoid(const Matrix& input);
};