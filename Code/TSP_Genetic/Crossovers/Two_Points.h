/**
 * @file	TSP_Genetic\Two_Points.h.
 *
 * @brief	Declares the two points Crossover class
 */

#pragma once
#include "Crossover.h"

/**@class TwoPoints
 *@brief	Concrete crossover strategy class. Implements the Crossover strategy.
 *
 * Two random crossover points are selected and the cities between this points of its two parents paths are swapped to get new paths (children).
 * Cross method creates children, pick the crossover points, performs the crossover on the parents (using helper twoCross function) and returns the result of this operation.
 */

class TwoPoints :
	public Crossover
{
public:
	TwoPoints() = default;
	~TwoPoints() = default;

	std::pair<Path, Path> cross(std::pair<Path, Path>& parents_pair) override;
private:

	/**
	 * @brief	 Generates a pair of random numbers which are the crossover points.
	 *
	 * @param size Number of cities in a path.
	 *
	 * @returns	std::pair crossover points;
	 */

	std::pair<int, int> randomize(int size);

	/**
	 * @brief	Crosses the parents and assigns the result to the child.
	 *
	 * @param [in,out]	child 	Child with empty path.
	 * @param 		  	border	Crossover points.
	 * @param 		  	p1	  	The first parent.
	 * @param 		  	p2	  	The second parent.
	 */

	void twoCross(Path& child, std::pair<int, int> border, Path p1, Path p2);
};
