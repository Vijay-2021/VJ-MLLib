#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../../linalg/includes/matrix.h"
#include "losses.h"
using namespace std;

class MSELoss : public Losses{
    public: 
        double computeLoss(const Matrix& y, const Matrix& y_hat) override; 
        ~MSELoss() {};
};