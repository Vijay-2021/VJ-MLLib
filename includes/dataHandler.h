#pragma once
#include "matrix.hpp"
#include "utils.h"

using namespace std;

class DataHandler {
    public:
        // default constructor
        DataHandler();

        // destructor, deletes dynamically allocated data
        ~DataHandler();

        // helper function to read in data from given .csv
        // bool readInCSV(const std::string& filename);

    private:
        // matrix labels
        vector<string> labels;

        // matrix
        Matrix matrix;
};