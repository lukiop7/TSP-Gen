/**
 * @file	TSP_Genetic\Uniform.h.
 *
 * @brief	Declares the uniform Crossover class
 */

#pragma once
#include "Crossover.h"


/**@class Uniform
 *@brief	Concrete crossover strategy class. Implements the Crossover strategy.
 *
 * In this crossover method each gene (city) is selected randomly from one of the corresponding genes of the parent chromosomes (paths).
 * Cross method creates children, performs the crossover on the parents (using helper uniformCross function) and returns the result of this operation.
 */

class Uniform :
	public Crossover
{
public:
	std::pair<Path, Path> cross(std::pair<Path, Path>& parents_pair) override;
private:

	/**
	 * @brief	Randomly returns 0 or 1. 
	 *
	 * 0 means city will be picked from the first parent, 1 from the second.
	 *
	 * @returns	0 or 1.
	 */

	int randomize();

	/**
	 * @brief	Crosses the parents and assigns the result to the child.
	 *
	 * @param [in,out]	child 	Child with empty path.
	 * @param 		  	p1	  	The first parent.
	 * @param 		  	p2	  	The second parent.
	 */

	void uniformCross(Path& child, Path& p1, Path& p2);
};
