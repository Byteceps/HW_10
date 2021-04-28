#include "cities.hh"


int main (int argc, char *argv[]){
    assert(argc == 2 && "This program takes exactly one filename as argument");

    //Create cities object from data in file given
    auto fin = std::ifstream(argv[1]);
    Cities cities;
    fin >> cities;

    //Variables
    unsigned ITERATIONS = 1000000;
    double best_distance = 50000;
    unsigned num_of_cities = cities.get_length();
    double distance = 0;

    //Loop to test city ordering iterations
    for(unsigned i = 0; i < ITERATIONS; i++){
        //Generate random permutation and compute total distance
        auto new_permutation = Cities::random_permutation(num_of_cities);
        distance = cities.total_path_distance(new_permutation);
        //Replace cities object with newly reordered one if distance is shortest seen so far
        if(distance < best_distance){
            cities = cities.reorder(new_permutation);
            best_distance = distance;
            std::cout << i << "   " << distance << std::endl;
        }
    }
    //Create new file "shorest.tsv" and write city ordering to it
    auto fout = std::ofstream("shortest.tsv");
    fout << cities;
    return 0;
}