#include "data_handler.h"
#include <queue>
#include <stack>
#include "Eigen/Core"
#include "Eigen/Eigenvalues"

using namespace std;

DataHandler::DataHandler() {
    matrix = Matrix();
}

DataHandler::~DataHandler() {
    matrix.~Matrix();
}

// reads in raw csv data
// bool DataHandler::readInCSV(const std::string& filename) {
//     ifstream ifs(filename);
//     if (!ifs.is_open()) return false;
//     string line;
//     // save labels
//     getline(ifs, line);
//     labels = utils::delimitLine(line, ',')

//     // read in the rest of the entries
//     while (ifs.good()) {

//         getline(ifs, line);
//         vector<string> delimited = utils::delimitLine(line, ',');
//         if (delimited.size() <= 1) { return true; }


//         string source = delimited.at(2);
//         pair<string,string> destination = {delimited.at(0), delimited.at(4)};

//         // id may not be a valid integer (bad data)
//         int id;
//         try { id = stoi(delimited.at(3)); }
//         catch(std::invalid_argument& e) { id = -1; }

//         // if airport does not exist, add new entry to map
//         if (airports.find(source) == airports.end()) {
//             airports.insert(pair<string, Airport*>(source, new Airport(source, id, destination)));
//             // prevent duplicate additions
//             if (airports.find(destination.second) == airports.end()) {
//                 airports[destination.second] = new Airport(destination.second);
//             }
//         }
//         else {
//             // if airport does exist, append destination
//             airports.at(source)->addDestination(destination);
//             if (airports.find(destination.second) == airports.end()) {
//                 airports[destination.second] = new Airport(destination.second);
//             }
//         }
//     }
//     return true;
// }