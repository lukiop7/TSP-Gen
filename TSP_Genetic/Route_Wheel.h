/**
 * @file	TSP_Genetic\Route_Wheel.h.
 *
 * @brief	Declares the route wheel class
 */

#pragma once
#include "Selection.h"

/**@class Route_Wheel
 *@brief	Concrete selection strategy class. Implements the Selection strategy.
 * 
 * Selection method picks two chromosomes with a probability which is proportional to its fitness.
 */

class Route_Wheel :
	public Selection
{
public:
	Route_Wheel() = default;
	~Route_Wheel() = default;
	std::pair<Path, Path> selection(std::unique_ptr<Generation>& generation) override;
private:
	/**
* @brief	Returns an index of the individual picked with a probability proportional to its fitness.

* @returns	Index.
*/
	int pickFromWheel(std::vector<double> wheel);
};
