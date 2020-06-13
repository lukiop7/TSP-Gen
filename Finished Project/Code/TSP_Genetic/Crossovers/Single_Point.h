/**
 * @file	TSP_Genetic\Single_Point.h.
 *
 * @brief	Declares the single point Crossover class
 */

#pragma once
#include "Crossover.h"

/**@class SinglePoint
 *@brief	Concrete crossover strategy class. Implements the Crossover strategy.
 *
 * Random crossover point is selected and the tails (cities after that point) of its two parents paths are swapped to get new paths (children).
 * Cross method creates children, pick the crossover point, performs the crossover on the parents (using helper singleCross function) and returns the result of this operation.
 */

class SinglePoint :
	public Crossover
{
public:

	SinglePoint() = default;
	~SinglePoint() = default;

	std::pair<Path, Path> cross(std::pair<Path, Path>& parents_pair) override;
private:
	/**
* @brief Generates random number which is the crossover point.
*
* @param size Number of cities in a path.
* @returns	Random number.
*/
	int randomize(int size);

	/**
	 * @brief	Crosses the parents and assigns the result to the child.
	 *
	 * @param [in,out]	child 	Child with empty path.
	 * @param 		  	border	Crossover point.
	 * @param 		  	p1	  	The first parent.
	 * @param 		  	p2	  	The second parent.
	 */

	void singleCross(Path& child, int border, Path p1, Path p2);
};
