#include "double_vector.h"
#include "double_read_vector.h"
#include "my_distance.h"  
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ifstream file("vectors_3D.txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    std::vector<double_vector> vectors;
    int id = 0;
    while (!file.eof()) {
        std::vector<double> elements = doubles_read_one_line(file);
        if (!elements.empty()) {
            vectors.push_back(double_vector(elements, id++));
        }
    }

    std::vector<my_distance> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosine_distance(vectors[i], vectors[j]);
            distances.push_back(my_distance(i, j, dist));
            distances.push_back(my_distance(j, i, dist));
        }
    }

    std::sort(distances.begin(), distances.end(), [](const my_distance & a, const my_distance & b) {
        return a.cos_distance < b.cos_distance;
    });

    for (const auto & dist : distances) {
        std::cout << dist.id_1 << " " << dist.id_2 << " cos dist = " << dist.cos_distance << std::endl;
    }

    return 0;
}
