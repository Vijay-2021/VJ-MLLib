#include "matrix.hpp"
#include <iostream>

int main() {
    std::cout << "main works in docker file" << std::endl;
    Matrix m(2,2);
    m.setElement(4,1,1);
    m.printMatrix();
    //return 0;
}