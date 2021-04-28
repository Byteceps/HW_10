# HW 9: Julian Prince and Aadit Bagdi

## The Exercise      
The traveling-salesperson problem (TSP) is a problem that’s very simple to formulate, and yet impossible to solve efficiently. As described in this Wikipedia page, TSP asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" In this assignment, we’ll write a program that searches for the best solution to the TSP problem among a set of randomized solutions.

## Building the program
* This program can be compiled with the following commands:
    * g++ -g -Wall -Wextra -pedantic -Werror -std=c++17 -fsanitize=address cities.cc tsp.cc -o city


## Design Choices
In the Cities class, we had to add two private data members: ```cityList``` and ```travelOrder```.
```cityList``` is a vector of ```std::pair``` types. This acts as a list of (x, y) coordinate pairs, where each pair represents a cities location in the coordinate plane. 
```travelOrder```is a vector of ```unsigned int``` types. This is a representation of the order in which each city is traveled to, and each int represents the index position of an ```std::pair``` in cityList.

```Cities::total_path_distance(premutation_t& ordering)```: For a given permutation of the cities in this object, this function computes how long (distance) it would take to traverse all the cities in the order of the permutation, and then returning to the first city. We added an additional helper function ```distance_between(coord_t start, coord_t end)``` that computes the distance between two coordinate points using the distance formula. 

```Cities::reorder(permutation&t ordering)```:Given a permutation, this function returns a new Cities object where the order of the cities reflects the original order of this class after reordering with the given ordering. So for example, the ordering { 1, 0 } simply swaps the first two elements (coordinates) in the new Cities object.

```static random_permutation(unsigned len)```: returns a random permutation of integers in the range ```0``` to ```len - 1 ```. It does so by creating a vector of all integers in range ```0``` to ```len - 1```, and then randomly shuffling it using ```std::shuffle```

We overloaded ```operator<<``` and ```operator>>``` to allow for the reading and writing of cities objects to a stream. This makes filling a Cities object with coordinate pairs stored in a ```.tsv``` file very easy, with notation like ```fin >> Cities```. Similarily, cities coordinate pairs can be easily output to a file with notation like ```fout << Cities```



```

```