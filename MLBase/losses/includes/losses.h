#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
using namespace std;

class Losses {
    public: 
        virtual double computeLoss(const Matrix& y, const Matrix& y_hat) { return 0; };
        
};