#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("Testing dot_product") {
    double_vector v1({1.0, 2.5, 0.5}, 0);
    double_vector v2({1.0, 3.6, 1.9}, 1);

    CHECK(dot_product(v1, v1) == doctest::Approx(7.5));
    CHECK(dot_product(v1, v2) == doctest::Approx(10.95));
    CHECK(dot_product(v2, v2) == doctest::Approx(17.57));
}

TEST_CASE("Testing magnitude") {
    double_vector v1({1.0, 2.5, 0.5}, 0);
    double_vector v2({1.0, 3.6, 1.9}, 1);

    CHECK(magnitude(v1) == doctest::Approx(sqrt(7.5)));
    CHECK(magnitude(v2) == doctest::Approx(sqrt(17.57)));
}

TEST_CASE("Testing cosine_distance") {
    double_vector v1({1.0, 2.5, 0.5}, 0);
    double_vector v2({1.0, 3.6, 1.9}, 1);
    double_vector v3({1.0, 1.0, 1.0}, 2);
    double_vector zero_vector({0.0, 0.0, 0.0}, 3);
    double_vector negative_vector({-1.0, -2.5, -0.5}, 4);
    double_vector nearly_parallel_1({1.0, 1.0, 1.0}, 4);
    double_vector nearly_parallel_2({1.001, 0.999, 1.0}, 5);

    REQUIRE(cosine_distance(v1, v2) >= 0.0); 
    REQUIRE(cosine_distance(v1, v1) == doctest::Approx(0.0)); 
    WARN(cosine_distance(v1, v3) != 1.0); 
    CHECK_FALSE(std::isfinite(cosine_distance(v1, zero_vector)));
    CHECK(cosine_distance(v1, negative_vector) >= 0.0);
    double nearly_parallel_dist = cosine_distance(nearly_parallel_1, nearly_parallel_2);
    CHECK(nearly_parallel_dist >= 0.0);
    CHECK(nearly_parallel_dist < 0.1);
}

