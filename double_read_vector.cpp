#include "double_read_vector.h"
#include <sstream>
#include <string>

std::vector<double> doubles_read_one_line(std::istream& in_stream) {
    std::string line;
    std::getline(in_stream, line);
    std::stringstream ss(line);
    std::vector<double> values;
    double value;
    while (ss >> value) {
        values.push_back(value);
    }
    return values;
}
