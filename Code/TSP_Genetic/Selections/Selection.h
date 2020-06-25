/**
 * @file	TSP_Genetic\Selection.h.
 *
 * @brief	Declares the selection strategy interface class
 */

#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <TGUI/TGUI.hpp>

#include "../Generation/Generation.h"
#include "../Helpers/helpers.h"


/**@class Selection
 *@brief	Abstract class for selection strategy interface. */

class Selection
{
public:
	Selection() = default;
	virtual ~Selection() = default;

	/**
	 * @brief	Selects two chromosomes from the generation. Method used to execute the selection strategy.
	 * 
	 * @param generation	The generation.
	 *
	 * @returns	std::pair containing selected chromosomes (parents);
	 */

	virtual std::pair<Path, Path> selection(std::unique_ptr<Generation>& generation);
};
