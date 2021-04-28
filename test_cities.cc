#include <iostream>
#include <fstream>
#include "cities.hh"
int main() {
    auto fin = std::ifstream("five.tsv");
    Cities cities;
    fin >> cities;
    output_list(cities);
    std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n"; // Should be 48.8699
    std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n"; // Should be 53.4243
    Cities cities_2 = cities.reorder({1, 0});
    output_list(cities_2);
    auto newPerm = Cities::random_permutation(5);
    for (auto i : newPerm) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    Cities cities_3 = cities.reorder(newPerm);
    output_list(cities_3);
    std::cout << cities_3.total_path_distance(newPerm) << "\n";
    auto fout = std::ofstream("test.tsv");
    fout << cities_3;
    return 0;
}