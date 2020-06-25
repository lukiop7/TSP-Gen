/**
 * @file	TSP_Genetic\Fitness.h.
 *
 * @brief	Declares the fitness class
 */

#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <TGUI/TGUI.hpp>

#include "../Generation/Generation.h"


/**@class Fitness
 *
 *@brief	Fitness class. */

class Fitness
{
public:

	/** @brief	Default constructor */

	Fitness()=default;

	/** @brief	Destructor */

	~Fitness()=default;

	/**
	 * @brief	Calculates the fitness of each individual in the generation.
	 *
	 * 
	 * Sorts the generation by fitness in descending order.
	 * @param 	generation	The generation.
	 */

	void calculateFitness(std::unique_ptr<Generation>& generation);
};
