#include "../includes/MSELoss.h"

double MSELoss::computeLoss(const Matrix& y, const Matrix& y_hat) {
    Matrix new_mat = (y - y_hat);
    new_mat = new_mat * new_mat;
    return new_mat.sum() / y.elemCount();
}