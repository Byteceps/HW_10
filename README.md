# HW 10: Traveling Salesperson Problem Part 2

**By: Aadit Bagdi, Cole Nemec, Julian Prince, and Taylor Blair**

A continuation of HW 9 ([Aadit & Julian's solution](https://github.com/Byteceps/HW_9_Julian_Aadit), [Cole's solution](https://github.com/deeptronos/reed-csci221-hw9), [Taylor's solution](https://github.com/Goodernews/CS-221/tree/main/Homeworks/HW_9)). Tasked with improving upon a bogo route finding solution by using genetic algorithims to iteratively find a better route. 

Genetic algorithims are adept at this problem as it is an NP complete problem where an optimal route can be found using reinforcment learning by swapping the orderings of various cities.


# `Cities`

We opted to use [Aadit & Julian's solution](https://github.com/Byteceps/HW_9_Julian_Aadit) to Homework 9 for the base `Cities` class.

# `Chromosome`

The chromosome class is used...

Intial code and outline was provided by Eitan Frachtenberg.

## Constructor and Destructor

The constructor and destructor were both set to the default

## `is_valid()` *Julian Prince*

`is_valid` is used to confirm that there is a complete ordering indiex vector

Using the STL for the following process:
 + The number of elements is counted
	 + If size is less than one, then it is an invalid vector
 + Copy of the vector is sorted
 + Checks if there are any duplicates
 	+ If there is, then it is an invalid vector
 + Checks if there are any gaps 
 	+ If there are, then the vector is invalid

## `calculate_fitness()` *Julian Prince & Taylor Blair*

This is the reward calculating component of the Chromosome class. 

It works by taking the length of a given solution and inversing the returned length, thus rewarding a shorter route.

Using the inverse of the length could be problmatic as it increases rewards exponentially (d/dx of 1/x is ln(x), ln(x)=y is e^y=x). In addition, there is a contraint as the returned value is a double. The larger the path, the greater the likelihood of truncation.  

## `mutate()` *Julian Prince*




## `is_in_range()` *Aadit Bagdi*


## `create_crossover_child()` **Unclaimed**


## `recombine()` *Aadit Bagdi & Julian Prince*


# Deme

`Deme` repesents a portion of the population (Derived from the greek word *demos*, or people)

In this assignment Deme is the population of genetic ... 

## Constructor and Destructor

The constructor and destructor were set to the default

## `get_best()` **Unclaimed**


## `select_parent()` **Unclaimed**



## `compute_next_generation()` **Unclaimed**


# TSP

TSP, short for travelling salesperson problem, are the two files that encompass our main function.

TAYLOR WILL PUT GRAPHS AND NUMBERS HERE HIGHLIGHTING THE IMPROVMENT.

# Notes

We would like to give a special thanks to the following individuals for assisting in both outlining, coding, and rubber ducking our code:
 + [Eitan Frachtenberg](https://github.com/eitanf)
	 + All files named
 + Ian Wahbe
	 + Recombine
