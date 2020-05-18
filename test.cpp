#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Test1") {
    studentas s1("a", "b", 7),
        s2("c", "d", 4.2);
    SECTION("pazymiu palyginimas") {
        REQUIRE((s1 >= s2) == true);
        REQUIRE((s2 < s1) == true);
    }
    studentas s3 = s2;
    SECTION("ar lygus pazymaiai") {
        REQUIRE((s3.egz == s2.egz) == true);
    }
}
TEST_CASE("Test2") {
    std::vector<int> hw1{ 2, 4, 6 }, hw2{ 1, 4, 1, 4 }, hw3{ 8 };
    int hw1Size = 3, hw2Size = 4, hw3Size = 1;

    SECTION("Vidurkis") {
        REQUIRE(vidurkis(hw1, hw1Size) == 4);
        REQUIRE(vidurkis(hw2, hw2Size) == 2.5);
    }
    SECTION("Mediana") {
        REQUIRE(mediana(hw1, hw1Size) == 4);
        REQUIRE(mediana(hw3, hw3Size) == 8);

    }
    SECTION("Galutinis ivertinimas") {
        REQUIRE(Galutinis(hw1, 5, 'v') == 4.6);
        REQUIRE(Galutinis(hw2, 7, 'v') == 5.2);
        REQUIRE(Galutinis(hw3, 9, 'm') == 8.6);
    }
}
