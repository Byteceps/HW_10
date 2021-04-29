/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
{
	if(mut_rate > 1.0 || mut_rate < 0.0){throw std::invalid_argument("Invalid mutation rate for a Deme. Ensure it's between 0-1.");} // Make sure mutation rate is within the range [0-1].

    mut_rate_ = mut_rate;
	for(unsigned i = 0; i < pop_size; ++i){
		pop_.push_back(Chromosome(cities_ptr)); // Add a newly-generated Chromosome to pop_.
				// Is the new keyword necessary here?
	}
}

// Clean up as necessary
Deme::~Deme()
{
  pop_.clear(); //Remove/destroy all chromosomes from the pop_ vector.
  std::vector<Chromosome*>().swap(pop_); // Create a vector without allocating any memory to it and swap it with pop_, deallocating the memory used by pop_.
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  // Add your implementation here
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  bool comp_fit = [] (auto city_a, auto city_b){ //used for comparisons
	  return city_a->calculate_fitness()<city_b->calculate_fitness();};
  //calls `calculate_fitness()` on two, compares which is better fit

  Chromosome best_chrome = std::max(pop_.begin(), pop_.end(), comp_fit); //finds chromosome with best fit
  Chromosome& copy_chrome = best_chrome; //makes a copy
  return new(copy_chrome); //returns a pointer to the copy 
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  // Add your implementation here
}
