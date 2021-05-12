# HW 10: Traveling Salesperson Problem Part 2

**By: Aadit Bagdi, Cole Nemec, Julian Prince, and Taylor Blair**

A continuation of HW 9 ([Aadit & Julian's solution](https://github.com/Byteceps/HW_9_Julian_Aadit), [Cole's solution](https://github.com/deeptronos/reed-csci221-hw9), [Taylor's solution](https://github.com/Goodernews/CS-221/tree/main/Homeworks/HW_9)). Tasked with improving upon a bogo route finding solution by using genetic algorithms to iteratively find a better route. 

Genetic algorithms are adept at this problem as it is an NP complete problem where an optimal route can be found using reinforcement learning by swapping the orderings of various cities.


# `Cities`

We opted to use [Aadit & Julian's solution](https://github.com/Byteceps/HW_9_Julian_Aadit) to Homework 9 for the base `Cities` class.

Minor changes were made to make the file compatible with the provided `TSP.cc` file.

# `Chromosome`

The chromosome class is used to define an individual gene. Each chromosome has an ordering 

Initial code and outline was provided by Eitan Frachtenberg.

## Constructor and Destructor

The constructor and destructor were both set to the default

## `is_valid()` *Julian Prince & Taylor Blair*

`is_valid` is used to confirm that there is a complete ordering index vector

It has an O(n) complexity.

It creates a vector of booleans that represents what values it has seen in a theoretical ordering. It goes through the ordering list element by element. If it hasn't seen an element before (value appears as false in the seen vector) it flips the boolean to true at the given indice. If it has seen an element before, it returns false.

## `calculate_fitness()` *Julian Prince & Taylor Blair*

This is the reward calculating component of the Chromosome class. 

It works by taking the length of a given solution and multiplies it by negative one. Because the distance is always a non-negative number, this means that the best fitness will be zero, and the worst will be negative infinity (ignoring the restrictions of a double). 

## `mutate()` *Julian Prince*

Picks two random numbers within the size of the index and swaps the ordering at those two index values using `std::iter_swap`.

## `is_in_range()` *Aadit Bagdi & Cole Nemec*

Checks that a given value is within a subset of a half open range of the ordering.

## `recombine()` *Aadit Bagdi & Julian Prince*

Creates two children from two parents using the `create_crossover_child` and `mutate` methods. Returns a pair of chromosomes. 


# Deme

`Deme` represents a portion of the population (Derived from the greek word *demos*, or people)

In this assignment Deme is the population of genetic ... 

## Constructor and Destructor *Cole Nemec & Taylor Blair*
The constructor for a Deme checks that the passed mutation rate is within the valid range from 0 to 1, then sets the object's `mut_rate` and populates its population (`pop_`) with Chromosomes based upon the passed Cities pointer, up to the passed population size (`pop_size`).
The destructor for a Deme `delete`s each member of the `pop_`,


## `get_best()` *Taylor Blair*

`get_best` returns a pointer to the chromosome with the best fitness.

Using the STL to find the max chromosome in the `pop_` vector.

Comparisons are performed using `comp_fitness()` which calls `calculate_fitness()` from the `Chromosome` class to make comparisons.

## `select_parent()` *Cole Nemec*
Returns a pointer to a Chromosome. 

The returned chromosome is determined using the "Roulette Wheel" technique, which is implemented here as follows:
* Calculate S - the sum of the Deme's population's fitnesses.
  * `std::acumulate()` was used for this step, and an additional function, `fitnessAccumulation()`, was created to serve as the `op` parameter in `accumulate`.
* Generate R - a random number between 0 and S.
* Starting from the top of the population, keep adding the fitness of each member of the population to the partial sum P, until P >= R.
* The individual for which P equals or exceeds R is the chosen individual.


## `compute_next_generation()` **Julian Prince**

```compute_next_generation()``` evolves a single generation of chromosomes. This method selects `pop_size / 2` pairs of chromosomes through the `select_parent()` method. Each chromosome in the pair has `mut_rate` probability of being selected for mutation. The new pair is `recombine()`'d to generate a new pair of chromosomes stored in the deme. After `pop_size` new chromsomes have been generated, the old generation is deleted. 

# TSP

TSP, short for travelling salesperson problem, are the two files that encompass our main function.

The tsp.cc file was created by Eitan Frachtenberg. Minor tweaks were made to make it compatible with the `cities.cc` file made by Aadit & Julian.

## Previous results

Because we are using code borrowed from Aadit & Julians solution, we opted to use the routes and graphics they had generated. Previously, the best challenge route had a route distance of about 19,000.
![old-challenge-route](images/HW_9/challenge_route.gif) 
*The* `shortest.tsv` *in the upper right is a formatting mistake.*

It took 100,000 iterations to find that route.

![old-challenge-speed](images/HW_9/challenge_speed.gif)

Of the 50 factorial routes, only 3.288*10^-57% are actually explored.



# Notes

We would like to give a special thanks to the following individuals for their assistance in both outlining, coding, and rubber ducking our code:
 + [Eitan Frachtenberg](https://github.com/eitanf)
	 + All files named
 + [David Ramirez](https://www.reed.edu/faculty-profiles/profiles/ramirez-david.html)
	 + `get_best`
	 + `calculate_fitness`
	 + `README.md`
 + Ian Wahbe
	 + `recombine`
