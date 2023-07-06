#pragma once

#include <iostream>
#include <vector>
#include <cstddef> 
#include <stdexcept>
#include <string>
#include "../../linalg/includes/matrix.hpp"
using namespace std;

class Losses {
    static double MeanSquaredError(const Matrix& y, const Matrix& y_hat); 
};