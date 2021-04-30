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
		pop_.push_back(new Chromosome(cities_ptr)); // Add a newly-generated Chromosome to pop_.
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

bool comp_fit(Chromosome* city_a, Chromosome* city_b)
{ //used for comparisons in get best
	  return city_a->get_fitness()<city_b->get_fitness();
}


const Chromosome* Deme::get_best() const
{ 
  return std::max_element(pop_.begin(), pop_.end(), comp_fit)[0]; //finds chromosome with best fit
}

// Function for op parameter of std::acumulate, as used in select_parent().
double fitnessAccumulation(double sum, Chromosome* chromosome){
	return sum + chromosome->get_fitness(); // Add the fitness of chromosome to sum and return it.
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{

	double sumOfFitness = std::accumulate(pop_.begin(), pop_.end(), 0.0, fitnessAccumulation);

	//Calculate S
	for(Chromosome* pChromosome:pop_){ //For each chromosome in our population...
		sumOfFitness += pChromosome->get_fitness(); // Add the chromosome's fitness to the sum.
	}

	//Calculate R
	std::uniform_real_distribution<double> distribution (0.0, sumOfFitness); // distribution will return a double between 0 and sumOfFitness when called with a generator.
	double R = distribution(generator_); // generate R.

	double P; // Initialize P

	for(Chromosome* chromo:pop_){ // For each chromosome in our population...
		P += chromo->get_fitness(); // Add the fitness of the chromosome to P.

		if(P >= R){ //If P exceeds R...
			return chromo; // Return the current chromosome!
		}
	}

	return nullptr; // Default return statement :P

}
