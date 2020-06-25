/**
 * @file	TSP_Genetic\City.h.
 *
 * @brief	Declares the city class
 */

#pragma once
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

/**@class City
 *@brief	Represents the city. */

class City
{
public:

	/**
	 * @brief	 Calculates the distance between this and the given city.
	 *
	 *
	 * @param 	a	A City to process.
	 *
	 * @returns	The distance between cities.
	 */

	double distanceTo(City& a);

	/**
	 * @brief	Gets the identifier
	 *
	 * @returns	The identifier.
	 */

	int getId() const;

	/**
	 * @brief	Get x coordinate
	 *
	 * @returns	The x coordinate.
	 */

	double getX() const;

	/**
	 * @brief	Returns the reference to the vector with distances to each city.
	 *
	 * 
	 * @returns	Vector with distances.
	 */

	std::vector<double>& getDistances();

	/**
	 * @brief	Get y coordinate
	 *
	 * @returns	The y coordinate.
	 */

	double getY() const;

	/**
	 * @brief	Equality operator
	 *
	 * @param 	lhs	The first city to compare.
	 * @param 	rhs	The second city  to compare.
	 *
	 * @returns	True if the parameters are considered equivalent.
	 */

	friend bool operator==(const City& lhs, const City& rhs)
	{
		return lhs.id == rhs.id
			&& lhs.x == rhs.x
			&& lhs.y == rhs.y;
	}

	/**
	 * @brief	Less-than comparison operator
	 *
	 * @param 	lhs	The first city to compare.
	 * @param 	rhs	The second city to compare.
	 *
	 * @returns	True if the first parameter is less than the second.
	 */

	friend bool operator<(const City& lhs, const City& rhs)
	{
		return lhs.id < rhs.id;
	}

	/**
	 * @brief	Constructor. 
	 *Resizes the vector so that it can hold the distances to all cities.
	 *
	 * @param 	_x 	The x coordinate.
	 * @param 	_y 	The y coordinate.
	 * @param 	_id	The identifier.
	 * @param 	n  	The number of cities.
	 */

	City(double _x, double _y, int _id, int n) : id(_id), x(_x), y(_y)
	{
		distances.resize(n);
	}

	/**
	 * @brief	Constructor for the circle representation
	 *
	 * Constructs city using the Vector with x and y coordinates. This constructor is used when the cities lie on the circle.
	 * @param 	coords	The coordinates.
	 * @param 	_id   	The identifier.
	 * @param 	n	  The number of cities.
	 */

	City(sf::Vector2f coords, int _id, int n) : id(_id), x(coords.x), y(coords.y)
	{
		distances.resize(n);
	}

	/**
	 * @brief	Constructor
	 *
	 * @param 	dist  	The distances between cities.
	 * @param 	coords	The coordinates.
	 * @param 	_id   	The identifier.
	 * @param 	n	  	The number of cities.
	 */

	City(std::vector<double> dist, sf::Vector2f coords, int _id, int n);
private:
	/** @brief	The identifier */
	int id;

	/** @brief	The x coordinate.*/
	double x;
	/** @brief	The y coordinate. */
	double y;
	/** @brief	The distances to other cities */
	std::vector<double> distances;
};
