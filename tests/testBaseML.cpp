#include "../linalg/includes/matrix.h"
#include "../MLBase/losses/includes/losses.h"
#include "../MLBase/losses/includes/MSELoss.h"
#include "../MLBase/activations/includes/activations.h"
#include "../MLBase/activations/includes/ReLU.h"
#include "../MLBase/activations/includes/Sigmoid.h"
#include <catch2/catch_test_macros.hpp>

// part-1: Basic Matrix Functionality

TEST_CASE("Test Basic Loss Computation", "[weight=1][part=1]") {
    Matrix left_hand = Matrix::ones(5,5);
    double data[25];
    for(size_t i = 0; i < 25; i++) {
        data[i] = i;
    }
    Matrix right_hand(data, 5, 5);
    MSELoss test_loss;
    double loss = test_loss.computeLoss(left_hand, right_hand);
    REQUIRE(loss == 173.0); 
}

TEST_CASE("Test Basic ReLU Activation", "[weight=1][part=1]") {
    double forward_data[9] = {1.9, 0, -3, 400000, 2, -2.797979, 3, 14, -5};
    Matrix forward_input(forward_data, 3, 3);
    double forward_output[9] = {1.9, 0, 0, 400000, 2, 0, 3, 14, 0};
    Matrix forward_expected_matrix(forward_output, 3, 3);
    ReLU activ;
    Matrix forward_calculated_matrix = activ.computeActivation(forward_input);

    REQUIRE(forward_calculated_matrix == forward_expected_matrix); 
}

TEST_CASE("Test Basic Sigmoid Activation", "[weight=1][part=1]") { 
    double forward_data[6] = {0.5, 0, -3, 400000, -40000, -2.797979};
    Matrix forward_input(forward_data, 3, 2);
    double forward_output[6] = {0.622459331, 0.5, 0.047426, 1, -1, 0.057433};
    Matrix forward_expected_matrix(forward_output, 3, 2);
    Sigmoid activ;
    Matrix forward_calculated_matrix = activ.computeActivation(forward_input);

    REQUIRE(forward_calculated_matrix.approxEquals(5,forward_expected_matrix));


}
