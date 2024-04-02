#include "double_vector.h"

double square(const double & d) {
    return d * d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double product = 0.0;
    for (size_t i = 0; i < one.elements.size(); i++) {
        product += one.elements[i] * two.elements[i];
    }
    return product;
}

double magnitude(const double_vector & my_vector) {
    double mag = 0.0;
    for (double elem : my_vector.elements) {
        mag += square(elem);
    }
    return sqrt(mag);
}

double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot = dot_product(one, two);
    double mag_one = magnitude(one);
    double mag_two = magnitude(two);
    double d = dot / (mag_one * mag_two);
    if (d > 1.0) {
        d = 1.0;
    }

    if (d < -1.0) {
        d = -1.0;
    }
    return acos(d);

}
