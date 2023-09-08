#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
using namespace std;

class Activation {
    public: 
        virtual Matrix computeGradient(const Matrix& upstream_gradient) {return Matrix::zeros(1,1);};
        virtual Matrix computeActivation(const Matrix& input) {return Matrix::zeros(1,1);};
       
};