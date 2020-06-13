/**
 * @file	TSP_Genetic\Crossover.h.
 *
 * @brief	Declares the crossover strategy interface class
 */

#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <TGUI/TGUI.hpp>
#include "Generation.h"
#include "City.h"
#include "Path.h"

/**@class Crossover
 *@brief	Abstract class for crossover strategy interface. */

class Crossover
{
public:
	Crossover() = default;
	virtual ~Crossover() = default;
	/**
	 * @brief	Crosses a given pair of parents and returns their children. 
	 * 			The paths from  parents are mixed, the result of that operation creates the path for the children.
	 *
	 * @param 	parents_pair	Pair of two individuals(parents).
	 *
	 * @returns	std::pair containing new individuals (children) resulting from their crossing;
	 */

	virtual std::pair<Path, Path> cross(std::pair<Path, Path>& parents_pair);
};
