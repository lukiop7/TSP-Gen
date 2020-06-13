/**
 * @file	TSP_Genetic\Tournament.h.
 *
 * @brief	Declares the tournament class
 */

#pragma once
#include "Selection.h"

/**@class Tournament
 *@brief	Concrete selection strategy class. Implements the Selection strategy.
 *
 * Selection method picks the two fittest individuals from a randomly selected pool of four.
 */
class Tournament :
	public Selection
{
public:
	Tournament() = default;
	~Tournament() = default;
	std::pair<Path, Path> selection(std::unique_ptr<Generation>& generation) override;
private:
	/**
* @brief Generates random number which is an index of the individual from the pool.
*
* @returns	Random number.
*/
	int randomize(int size);
};
