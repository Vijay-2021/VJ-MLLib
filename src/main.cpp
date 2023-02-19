#include "../linalg/includes/matrix.hpp"
#include "../linalg/includes/dataHandler.h"
#include <iostream>

int main() {
    std::cout << "main works in docker file" << std::endl;
    DataHandler d = DataHandler();
    d.readInCSV("../tests/data/small1.csv");
    Matrix m = d.getMatrix();
    m.printMatrix();
    return 0;
}