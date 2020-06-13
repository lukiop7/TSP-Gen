/**
 * @file	TSP_Genetic\Path.h.
 *
 * @brief	Declares the path class
 */

#pragma once
#include "City.h"
#include <vector>
#include <iostream>

/**@class Path
 *
 *@brief	Represents the path.*/

class Path
{
public:

	/** @brief	Default constructor */

	Path() = default;

	/**
	 * @brief	Constructor
	 *
	 * @param 	m	Number of cities.
	 */

	Path(int m) : amount(0), max(m), complete(false), distance(0), fitness(0)
	{
	}

	/**
	 * @brief	Copy constructor
	 *
	 * @param 	p	A Path to process.
	 */

	Path(const Path& p);

	/**
	 * @brief	Adds a city to the path.
	 *When the path is full (all cities have been added) calculates the total distance of the path.
	 * 
	 * @param 	city	The city to add.
	 */

	void addCity(City city);

	/**
	 * @brief	Less-than comparison operator
	 *
	 * @param 	lhs	The first instance to compare.
	 * @param 	rhs	The second instance to compare.
	 *
	 * @returns	This is true if the second path is more fit than the first.
	 */

	friend bool operator<(const Path& lhs, const Path& rhs)
	{
		return lhs.fitness < rhs.fitness;
	}

	/**
	 * @brief	Less-than-or-equal comparison operator
	 *
	 * @param 	lhs	The first instance to compare.
	 * @param 	rhs	The second instance to compare.
	 *
	 * @returns	True if the first path is worse than or equal to the second.
	 */

	friend bool operator<=(const Path& lhs, const Path& rhs)
	{
		return !(rhs < lhs);
	}

	/**
	 * @brief	Greater-than comparison operator
	 *
	 * @param 	lhs	The first instance to compare.
	 * @param 	rhs	The second instance to compare.
	 *
	 * @returns	True if the first path is better than the second.
	 */

	friend bool operator>(const Path& lhs, const Path& rhs)
	{
		return rhs.fitness < lhs.fitness;
	}

	/**
	 * @brief	Greater-than-or-equal comparison operator
	 *
	 * @param 	lhs	The first instance to compare.
	 * @param 	rhs	The second instance to compare.
	 *
	 * @returns	True if the first path is better or equal to the second.
	 */

	friend bool operator>=(const Path& lhs, const Path& rhs)
	{
		return !(lhs < rhs);
	}

	/**
	 * @brief	Gets the maximum number of Cities
	 *
	 * @returns	Maximum number of Cities.
	 */

	int getMax() const;

	/**
	 * @brief	Gets the cities
	 *
	 * @returns	The reference to the cities vector.
	 */

	std::vector<City>& getCities();

	/**
	 * @brief	Sets the cities
	 *
	 * @param 	cities	Vector with cities.
	 */

	void setCities(std::vector<City> cities);

	/** @brief	Calculates the distance of the path. */

	void checkDistance();

	/**
	 * @brief	Gets the distance
	 *
	 * @returns	The distance.
	 */

	double getDistance() const;

	/**
	 * @brief	Gets the fitness
	 *
	 * @returns	The fitness.
	 */

	double getFitness() const;

	/**
	 * @brief	Sets the fitness
	 *
	 * @param 	fitness	The fitness.
	 */

	void setFitness(double fitness);
private:
	/** @brief	Current amount of the cities */
	int amount;
	/** @brief	Maximum number of the cities */
	int max;
	/** @brief	True if path is full */
	bool complete;

	/** @brief	The cities */
	std::vector<City> cities;

	/** @brief	The distance */
	double distance;
	/** @brief	The fitness */
	double fitness;
};
