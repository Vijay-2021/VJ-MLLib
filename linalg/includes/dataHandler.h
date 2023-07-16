#pragma once
#include "matrix.h"
#include "utils.h"
#include <fstream>

using namespace std;

class DataHandler {
    public:
        // default constructor
        DataHandler();

        // destructor, deletes dynamically allocated data
        ~DataHandler();

        // getters
        Matrix& getMatrix();
        vector<string>& getLabels();

        // helper function to read in data from given .csv
        bool readInCSV(const std::string& filename);

    private:
        // empty
        bool empty;

        // matrix labels
        vector<string> labels;

        // matrix
        Matrix matrix;
};