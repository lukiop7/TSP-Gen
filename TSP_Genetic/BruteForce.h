/**
 * @file	TSP_Genetic\BruteForce.h.
 *
 * @brief	Declares the brute force class
 */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <TGUI/TGUI.hpp>
#include <random>
#include "path.h"

/**@class BruteForce   
 * @brief	Brute Force class.
 * 
 * Class responsible for solving TSP using brute force method. 
 */

class BruteForce
{
public:

	/**
	 * @brief	Constructor
	 *
	 * @param 	c	Pointer to the vector with cities.
	 */

	BruteForce(std::shared_ptr<std::vector<City>>& c);

	/** @brief	Generates all possible paths.
	 * 
	 * 
	 */

	void permutations();

	/**
	 * @brief	Displays the first and the best path on the screen.
	 *
	 *
	 *
	 * @param 	canvas1	The first canvas.
	 * @param 	canvas2	The second canvas.
	 */

	void displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2);

	/**
	 * @brief Calls functions in order to generate the solution.
	 *
	 *
	 * 
	 * @param 	canvas1	The first canvas.
	 * @param 	canvas2	The second canvas.
	 */

	void bruteForce(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2);

	/**
	 * @brief	Gets the best distance 
	 *
	 * @returns	Shortest distance.
	 */

	double getBest() const;

	/**
	 * @brief	Gets the best path
	 *
	 * @returns	The best path.
	 */

	std::shared_ptr<Path>& getBestPath();

private:
	/** @brief	The cities */
	std::shared_ptr<std::vector<City>> cities;
	/** @brief	Pointer to the shortest path*/
	std::shared_ptr<Path> best_path;
	/** @brief	Vector with all possible paths*/
	std::vector<Path> paths;
	/** @brief	Shortest distance */
	double best;
	/** @brief	Index of the best path*/
	int index_best;

	/** @brief	Number of cities*/
	const int cities_amount;
};
