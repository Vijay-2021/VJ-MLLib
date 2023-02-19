#include "../includes/dataHandler.h"

using namespace std;

DataHandler::DataHandler() {
    empty = true;
}

DataHandler::~DataHandler() {
    matrix.~Matrix();
}

Matrix& DataHandler::getMatrix() {
    if (empty) {
        throw std::runtime_error("matrix empty");
    }
    return matrix;
}

vector<string>& DataHandler::getLabels() {
    if (empty) {
        throw std::runtime_error("matrix empty");
    }
    return labels;
}

// reads in raw csv data
bool DataHandler::readInCSV(const std::string& filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) return false;
    string line;

    // save labels
    getline(ifs, line);
    labels = utils::delimitLine(line, ',');

    // create base matrix
    size_t labelSize = labels.size();
    matrix = Matrix(0, labelSize);

    // read in the rest of the entries
    size_t lineIdx = 1;
    while (ifs.good()) {

        getline(ifs, line);
        vector<string> delimited = utils::delimitLine(line, ',');
        size_t lineSize = delimited.size();
        if (lineSize <= 1) { 
            return true; 
        }
        else if (lineSize != labelSize) {
            throw std::length_error("line " + to_string(lineIdx) + 
                                    " has " + to_string(lineSize) + 
                                    " argument" + (lineSize == 1 ? "" : "s") +
                                    " (expected " + to_string(labelSize) + ")");
        }

        // copy to arr
        double* row = new double[lineSize];
        for (size_t i = 0; i < lineSize; i++) {
            // id may not be a valid integer (bad data)
            double val;
            try { val = std::stod(delimited[i]); }
            catch(std::invalid_argument& e) { val = 0; }
            row[i] = val;
        }
        // append
        matrix.appendRow(row, lineSize);
        empty = false;
        lineIdx++;
    }
    return true;
}
