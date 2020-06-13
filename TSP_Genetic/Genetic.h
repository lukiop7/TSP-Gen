/**
 * @file	TSP_Genetic\Genetic.h.
 *
 * @brief	Genetic Algorithm class.
 */

#pragma once
#include<vector>
#include <TGUI/TGUI.hpp>
#include "Generation.h"
#include "Mutation.h"
#include "Fitness.h"
#include "Single_Point.h"
#include "Two_Points.h"
#include "Uniform.h"
#include "Route_Wheel.h"
#include "Tournament.h"
#include "Random.h"

/**@class Genetic
 *@brief	Declares the Genetic Algorithm class. */

class Genetic
{
public:

	/**
	 * @brief	Constructor
	 *
	 * Creates unique pointers that manages objects used in the algorithm. Crossover and selection are created depending on the users choice. 
	 * Switch statements create and assign to interfaces pointers that manages objects that implement concrete strategies. 
	 * @param 		  	c		   Number of cities.
	 * @param 		  	s		   Size of the generation.
	 * @param 		  	r		   Mutation ratio.
	 * @param 	cit		   	Pointer to the vector with cities.
	 * @param 		  	sel_strat  	Selection strategy chosen by the user.
	 * @param 		  	cross_strat	Crossover strategy chosen by the user.
	 */

	Genetic(int c, int s, double r, std::shared_ptr<std::vector<City>>& cit, int sel_strat, int cross_strat);

	/** @brief	Performs genetic algorithm on the generation.
	 * 
	 * Calls appropriate functions from the other objects.
	 * If this is the first generation, it generates the chromosomes and calculate their fitnesses, otherwise calculate fitness, performs selection, crossover and mutation.
	 * Sets pointers to the best paths.
	 */

	void geneticAlgorithm();

	/**
	 * @brief	Calls function from the generation class displaying best current and best ever solutions.
	 *
	 * 
	 * @param 	canvas1	The first canvas for current best.
	 * @param 	canvas2	The second canvas for best ever.
	 */

	void displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2);

	/**
	 * @brief	Gets the number of the best generation.
	 *
	 * @returns	The number of the best generation.
	 */

	int getCntbest() const;

	/**
	 * @brief	Gets the number of the current generation.
	 *
	 * @returns	Current generation number.
	 */

	int getCnt() const;

	/**
	 * @brief	Gets the shortest distance.
	 *
	 * @returns	The shortest distance ever.
	 */

	double getShortest() const;

	/**
	 * @brief	Gets the shortest distance from the current generation.
	 *
	 * @returns	The shortest distance from the current generation.
	 */

	double getCurrentShortest() const;

	/**
	 * @brief	Gets pointer to the best path.
	 *
	 * @returns	Pointer to the best ever path.
	 */

	std::shared_ptr<Path>& getBest();
private:
	/** @brief	Size of the generation */
	const int gen_size;
	/** @brief	Mutation ratio */
	const double mut_ratio;
	/** @brief	Number of the current generation*/
	int gen_counter;
	/** @brief	Number of the best generation*/
	int cnt_best;
	/** @brief	Shortest distance ever */
	double shortest_distance;
	/** @brief	Shortest distance from the current generation */
	double current_shortest;
	/** @brief	Pointer to the crossover strategy interface*/
	std::unique_ptr<Crossover> crossover_strategy;
	/** @brief	Pointer to the selection strategy interface */
	std::unique_ptr<Selection> selection_strategy;
	/** @brief	Pointer to the mutation object*/
	std::unique_ptr<Mutation> mutation_strategy;
	/** @brief	Pointer to the fitness object*/
	std::unique_ptr<Fitness> fitness_strategy;
	/** @brief	Pointer to the generation object */
	std::unique_ptr<Generation> generation;
	/** @brief	Pointer to the best ever path */
	std::shared_ptr<Path> best_path;
	/** @brief	Pointer to the best path from the current generation */
	std::shared_ptr<Path> current_best_path;
	/** @brief	Pointer to the vector with cities */
	std::shared_ptr<std::vector<City>> cities;

	/** @brief	Calls function from the generation object which generates the initial population*/

	void generate();
};
