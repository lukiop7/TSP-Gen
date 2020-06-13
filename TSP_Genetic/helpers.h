/**
 * @file	TSP_Genetic\helpers.h.
 *
 * @brief	Namespace with helper functions
 */

#pragma once
#include <vector>

/**
 * @namespace	helpers
 *
 * @brief	Helper functions.
 */

namespace helpers
{
	/**
	 * @brief	Checks whether the vector contains the given value in the given range.
	 *
	 * @tparam	T	Generic type parameter.
	 * @param 	vec   	The vector.
	 * @param 	border	The range.
	 * @param 	value 	The value.
	 *
	 * @returns	True if the object is in this collection, false if not.
	 */

	template <class T>
	bool contains(const std::vector<T>& vec, const std::pair<int, int> border, const T& value)
	{
		return std::find(vec.begin(), vec.end() - (vec.size() - border.first - 1), value) != vec.end() - (vec.size() -
				border.first - 1)
			|| std::find(vec.begin() + border.second, vec.end(), value) != vec.end();
	}

	/**
	 * @brief	Checks whether the vector contains the given value in the range from the beginning to the given border.
	 *
	 * @tparam	T	Generic type parameter.
	 * @param 	vec   	The vector.
	 * @param 	border	The border.
	 * @param 	value 	The value.
	 *
	 * @returns	True if the object is in this collection, false if not.
	 */

	template <class T>
	bool contains(const std::vector<T>& vec, const int border, const T& value)
	{
		return std::find(vec.begin(), vec.end() - (vec.size() - border - 1), value) != vec.end() - (vec.size() - border
			- 1);
	}

	/**
	 * @brief	Checks whether the vector contains the given value.
	 *
	 * @tparam	T	Generic type parameter.
	 * @param 	vec  	The vector.
	 * @param 	value	The value.
	 *
	 * @returns	True if the object is in this collection, false if not.
	 */

	template <class T>
	bool contains(const std::vector<T>& vec, const T& value)
	{
		return std::find(vec.begin(), vec.end(), value) != vec.end();
	}
}
