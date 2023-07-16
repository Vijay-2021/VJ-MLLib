#include "../linalg/includes/matrix.h"
#include <catch2/catch_test_macros.hpp>

// part-1: Basic Matrix Functionality

TEST_CASE("Test Print Matrix", "[weight=1][part=1]") {
    Matrix m(2,2);
    m.printMatrix();
}

TEST_CASE("Test Get Element", "[weight=1][part=1]") {
    Matrix m(4,4);

    //check out of index access attempts 
    REQUIRE_THROWS(m.getElement(-1, -1));
    REQUIRE_THROWS(m.getElement(4,4));
    REQUIRE_THROWS(m.getElement(3, -1));
    REQUIRE_THROWS(m.getElement(-1, 3));
    REQUIRE_THROWS(m.getElement(3, 4));
    REQUIRE_THROWS(m.getElement(4, 3));

    //check corners to make sure there are no edge cases 
    REQUIRE(m.getElement(3,3) == 0);  
    REQUIRE(m.getElement(0,0) == 0); 
    REQUIRE(m.getElement(0, 3) == 0);
    REQUIRE(m.getElement(3, 0) == 0);
}

TEST_CASE("Test Set Element", "[weight=1][part=1]") {
    Matrix m(4,4);
    m.setElement(3, 0, 0);
    Matrix m2(4, 4);
    m2.setElement(3, 3, 2);
    REQUIRE(m.getElement(0,0) == 3);
    REQUIRE(m2.getElement(3, 2) == 3);

    REQUIRE_THROWS(m.setElement(1, -1, -1));
    REQUIRE_THROWS(m.setElement(1, 4, 4));
    REQUIRE_THROWS(m.setElement(1, -1, 3));
    REQUIRE_THROWS(m.setElement(1, 3, -1));
}

TEST_CASE("Test Constructor", "[weight=1][part=1]") {
    double data[25];
    for (size_t i = 0; i < 25; i++) {
        data[i] = i;
    }
    Matrix compare(5, 5);
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            compare.setElement(5*i + j, i, j);
        }
    }
    Matrix m(data, 5, 5);
    Matrix m2(compare);
    Matrix m3(4, 4);
    m3 = compare;
    Matrix m4(4, 4);
    Matrix m5(5, 5);
    REQUIRE(m == compare);
    REQUIRE(m2 == compare);
    REQUIRE(m3 == compare);
    REQUIRE_FALSE(m4 == compare);
    REQUIRE_FALSE(m5 == compare);
}

TEST_CASE("Test Matrix Product", "[weight=1][part=1]") {
    double data[9];
    double data2[12];
    double data3[12] = {11, 14, 17, 20, 20, 32, 44, 56, 29, 50, 71, 92};
    for (int i = 0; i < 9; i++) {
        data[i] = i;
    }
    for (int i = 0; i < 12; i++) {
        data2[i] = i - 3; 
    }

    Matrix m(data, 3, 3);
    Matrix m2(data2, 3, 4);

    Matrix compare(data3, 3,4);
    
    Matrix output = m.matrixProd(m2);
    

    REQUIRE(output == compare);

}


TEST_CASE("Test Matrix Transpose", "[weight=1][part=1]") {
    double data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double data2[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    double data3[12] = {11, 14, 17, 20, 20, 32, 44, 56, 29, 50, 71, 92};
    double data4[12] = {11, 20, 29, 14, 32, 50, 17, 44, 71, 20, 56, 92};
    
    Matrix test1(data, 3, 3);
    Matrix compare1(data2, 3, 3);
    Matrix test2(data3, 3, 4);
    Matrix compare2(data4, 4, 3);

    Matrix transpose1 = test1.transposeM();
    test2.transpose();

    REQUIRE(transpose1 == compare1);
    REQUIRE(test2 == compare2);

}


TEST_CASE("Test Matrix Add Column", "[weight=1][part=1]") {
    double data[12] = {11, 14, 17, 20, 20, 32, 44, 56, 29, 50, 71, 92};
    double data2[15] = {11, 14, 17, 20, 1, 20, 32, 44, 56, 2, 29, 50, 71, 92, 3};
    double data3[16] = {11, 14, 17, 20, 20, 32, 44, 56, 29, 50, 71, 92, 1, 2, 3, 4};
    double data4[15] = {11, 1, 14, 17, 20, 20, 2, 32, 44, 56, 29, 3, 50, 71, 92};
    double data5[16] = {11, 14, 17, 20, 1, 2, 3, 4, 20, 32, 44, 56, 29, 50, 71, 92 };
    

    double append1[3] = {1, 2, 3};
    double append2[4] = {1, 2, 3, 4};

    Matrix test1(data, 3, 4);
    Matrix test2(data, 3, 4);
    Matrix test3(data, 3, 4);
    Matrix test4(data, 3, 4);

    Matrix compare1(data2, 3, 5);
    Matrix compare2(data3, 4, 4);
    Matrix compare3(data4, 3, 5);
    Matrix compare4(data5, 4, 4);

    test1.appendCol(append1, 3);
    test2.appendRow(append2, 4);
    test3.addCol(append1, 3, 1);
    test4.addRow(append2, 4, 1);

    REQUIRE(test1 == compare1);
    REQUIRE(test2 == compare2);
    REQUIRE(test3 == compare3);
    REQUIRE(test4 == compare4);
    

}

TEST_CASE("Test Operator Overloads", "[weight=1][part=1]") {
    double constant_one = - 4;
    double constant_two = 7;
    double constant_three = 34.4958696;

    double a_array_start[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double b_array_start[9] = {-1, 3, -5, 7, -9, 11, -13, 15, -17};
    double c_array_start[16] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
    double d_array_start[16] = {-3, 5, 8, 4, 27, 3, 4, 5, 12, 32, -0.345, 2, 1, 32, 8, 14};

    double output_eq_one[9] = {6, 13, 8, 23, 10, 33, 12, 43, 14};

    Matrix A(a_array_start, 3, 3);
    Matrix B(b_array_start, 3, 3);
    Matrix C(3,3);
    C = ((A*6.0 + B*2.0)/2.0) + 4.0;
    Matrix compare(output_eq_one, 3, 3);
    REQUIRE(C == compare);
}

TEST_CASE("Test Zeros and Ones") {
    double zerosThreeByThree[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    double onesThreeByThree[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    double zerosMixed[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double onesMixed[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double zerosVector[3] = {0, 0, 0};
    double onesVector[3] = {1, 1, 1};

    Matrix zeroMatThreeByThree = Matrix::zeros(3, 3);
    Matrix oneMatThreeByThree = Matrix::ones(3, 3);
    Matrix zerosMatMixed = Matrix::zeros(6, 2);
    Matrix onesMatMixed = Matrix::ones(6, 2);
    Matrix zerosMatVector = Matrix::zeros(3, 1);
    Matrix onesMatVector = Matrix::ones(3, 1);

    
    Matrix zeroMatCompareThreeThree(zerosThreeByThree, 3, 3);
    Matrix oneMatCompareThreeThree(onesThreeByThree, 3, 3);
    Matrix zeroMatCompareMixed(zerosMixed, 6, 2);
    Matrix oneMatCompareMixed(onesMixed, 6, 2);
    Matrix zeroMatCompareVector(zerosVector, 3, 1);
    Matrix oneMatCompareVector(onesVector, 3, 1);

    REQUIRE(zeroMatCompareThreeThree == zeroMatThreeByThree);
    REQUIRE(oneMatCompareThreeThree == oneMatThreeByThree);
    REQUIRE(zeroMatCompareMixed == zerosMatMixed);
    REQUIRE(oneMatCompareMixed == onesMatMixed);
    REQUIRE(zeroMatCompareVector == zerosMatVector);
    REQUIRE(oneMatCompareVector == onesMatVector);


}
