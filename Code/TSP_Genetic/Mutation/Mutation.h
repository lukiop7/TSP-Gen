/**
 * @file	TSP_Genetic\Mutation.h.
 *
 * @brief	Declares the mutation class
 */

#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <TGUI/TGUI.hpp>

#include "../Generation/Generation.h"


/**@class Mutation  
 *  @brief Mutation class
 * 
 * Responsible for mutation.
 */

class Mutation
{
public:

	/**
	 * @brief	Constructor
	 *
	 * @param 	r	Mutation ratio.
	 */

	Mutation(double r);

	/** @brief	Destructor */

	~Mutation();

	/**
	 * @brief	Performs mutation on the generation.
	 *
	 * Picks the individuals from the generation and randomly swaps cities in its path. Individuals are picked with given probability.
	 * @param 	generation	The generation.
	 */

	void mutate(std::unique_ptr<Generation>& generation);
private:
	/** @brief	Mutation probability */
	double ratio;

	/**
	 * @brief	 Returns random number generated in a given range.
	 * @param 	i	The beginning of the range.
	 * @param 	j	The end of the range.
	 *
	 * @returns	Random Number.
	 */

	double randomize(int i, int j);
};
