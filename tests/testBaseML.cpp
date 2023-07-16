#include "../linalg/includes/matrix.h"
#include "../MLBase/includes/losses.h"
#include <catch2/catch_test_macros.hpp>

// part-1: Basic Matrix Functionality

TEST_CASE("Test Basic Loss Computation", "[weight=1][part=1]") {
    Matrix left_hand = Matrix::ones(5,5);
    double data[25];
    for(size_t i = 0; i < 25; i++) {
        data[i] = i;
    }
    Matrix right_hand(data, 5, 5);

    double loss = Losses::MeanSquaredError(left_hand, right_hand);
    REQUIRE(loss == 173.0);
}

