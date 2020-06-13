/**
 * @file	TSP_Genetic\Generation.h.
 *
 * @brief	Declares the generation class
 */

#pragma once
#include <vector>
#include <algorithm>
#include <TGUI/TGUI.hpp>
#include "City.h"
#include "Path.h"

/**@class Generation
 *@brief	Represents the generation.
 * 
 * Contains all individuals from the generation. 
 */

class Generation
{
public:

	/**
	 * @brief	Constructor
	 *
	 * 
	 * @param 		  	cs	Number of cities.
	 * @param 		  	s 	Size of the generation.
	 * @param 	c 	Pointer to the vector with cities.
	 */

	Generation(int cs, int s, std::shared_ptr<std::vector<City>>& c);

	/** @brief	Generates the initial population.
	 * 
	 *  Paths are generated randomly.
	 */

	void generate();

	/**
	 * @brief	Displays the shortest path from the current generation and the shortest ever.
	 *
	 * 
	 * @param 	canvas1	The first canvas for current best.
	 * @param 	canvas2	The second canvas for best ever.
	 */

	void displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2);

	/**
	 * @brief Gets the number of the current generation.
	 *
	 * 
	 * @returns	Number of the current generation.
	 */

	int getCounter() const;

	/**
	 * @brief	Sets a counter
	 *
	 * @param 	counter	The counter.
	 */

	void setCounter(int counter);

	/**
	 * @brief	Gets the number of cities
	 *
	 * @returns	Number of cities.
	 */

	const int getCitiesnb() const;

	/**
	 * @brief	Gets the size of the generation
	 *
	 * @returns	The size.
	 */

	const int getSize() const;

	/**
	 * @brief	Gets the shortest distance ever.
	 *
	 * @returns	The shortest distance.
	 */

	double getBest() const;

	/**
	 * @brief	Gets the shortest distance from the current generation
	 *
	 * @returns	The current best.
	 */

	double getCurrentBest() const;

	/**
	 * @brief	Gets the generation number of the best ever solution.
	 *
	 * @returns	The cntbest.
	 */

	int getCntbest() const;


	/**
	 * @brief	Gets pointer to the vector with cities.
	 *
	 * @returns	The cities.
	 */

	std::shared_ptr<std::vector<City>> getCities() const;

	/**
	 * @brief	Gets the vector with paths.
	 *
	 * @returns	Reference to the vector.
	 */

	std::vector<Path>& getPaths();

	/**
	 * @brief	Sets the paths
	 *
	 * @param 	paths	Vector with paths.
	 */

	void setPaths(std::vector<Path> paths);

	/** @brief	Checks which path from the generation is the best and if it is better than the best ever solution*/

	void checkBest();

	/**
	 * @brief	Gets pointer to the best ever path
	 *
	 * @returns	The best path.
	 */

	std::shared_ptr<Path>& getBestPath();
private:
	/** @brief	Number of the current generation */
	int generation_counter;
	/** @brief	Number of cities */
	const int cities_nb;
	/** @brief	Size of the generation */
	const int size;
	/** @brief	The shortest distance ever*/
	double best;
	/** @brief	The shortest distance from the current generation */
	double current_best;
	/** @brief	Generation number of the best ever solution */
	int cnt_best;
	/** @brief	Pointer to the best ever path*/
	std::shared_ptr<Path> best_path;
	/** @brief	Pointer to the best path from the current generation*/
	std::shared_ptr<Path> best_current;
	/** @brief	Pointer to the vector with cities */
	std::shared_ptr<std::vector<City>> cities;
	/** @brief	Vector with all paths from the current generation */
	std::vector<Path> paths;
};
