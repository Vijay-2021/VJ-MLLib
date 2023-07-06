#include "../linalg/includes/matrix.hpp"
#include <catch2/catch_test_macros.hpp>

// part-1: Basic Matrix Functionality

TEST_CASE("Test Print Matrix", "[weight=1][part=1]") {
    Matrix m(2,2);
    m.printMatrix();
}

