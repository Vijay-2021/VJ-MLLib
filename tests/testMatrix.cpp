#include "../includes/matrix.hpp"
#include <catch2/catch_test_macros.hpp>

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
    m.printMatrix();
    m2.printMatrix();
    REQUIRE(m.getElement(0,0) == 3);
    REQUIRE(m2.getElement(3, 2) == 3);

    REQUIRE_THROWS(m.setElement(1, -1, -1));
    REQUIRE_THROWS(m.setElement(1, 4, 4));
    REQUIRE_THROWS(m.setElement(1, -1, 3));
    REQUIRE_THROWS(m.setElement(1, 3, -1));
}

TEST_CASE("Test Constructor", "[weight=1][part=1]") {
    double data[25];
    for (int i = 0; i < 25; i++) {
        data[i] = i;
    }
    Matrix compare(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
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
    compare.printMatrix();
}






