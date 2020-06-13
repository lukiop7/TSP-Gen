/**
 * @file	TSP_Genetic\Random.h.
 *
 * @brief	Declares the random class.
 */

#pragma once
#include <random>
#include "Selection.h"

/**@class Random
 *@brief	Concrete selection strategy class. Implements the Selection strategy.
 * 
 * Selection method randomly picks 2 chromosomes from the generation.
 */

class Random :
	public Selection
{
public:
	Random() = default;
	~Random() = default;

	std::pair<Path, Path> selection(std::unique_ptr<Generation>& generation) override;
private:
	/**
 * @brief Generates random number which is an index of the selected individual.
 *
 * @returns	Random number.
 */
	int randomize(int size);
};
