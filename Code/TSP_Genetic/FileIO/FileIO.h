/**
 * @file	TSP_Genetic\FileIO.h.
 *
 * @brief	Declares the file i/o class
 */

#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "../Path/Path.h"
#include "../Exceptions/exceptions.h"
#include "TGUI/TGUI.hpp"


/**
 * @namespace	FileIO
 *
 * @brief	The functions of processing input and output files.
 */

namespace FileIO
{
	/**
	 * @brief Validates the path and extension of the input file.
	 *
	 * Checks the path and extension of the input file. Returns string containing the type of the input.
	 * @param 	path	Full pathname of the file.
	 * @throws FilePathExt if the path or extension is invalid.
	 * @throws FileOpen if the file cannot be opened.
	 * @returns	String containing the input type.
	 */

	std::string checkFile(std::string path);

	/**
	 * @brief	Output file for the genetic algorithm solution.
	 *
	 * Generates the output file for the genetic algorithm solution.
	 * @param 		  	path  	Full pathname of the file.
	 * @param 		  	number	Generation number.
	 * @param [in,out]	best  	The best path.
	 * @param [in,out]	cities	Cities.
	 * @throws FileOpen if the file cannot be created.
	 * @throws FilePath if the path is invalid.
	 */

	void geneticFile(std::string path, int number, std::shared_ptr<Path>& best,
	                 std::shared_ptr<std::vector<City>>& cities);

	/**
	 * @brief	Output file for the brute force solution
	 *
	 * Generates the output file for the brute force solution.
	 * @param 		  	path  	Full pathname of the file.
	 * @param [in,out]	best  	The best path.
	 * @param [in,out]	cities	Cities.
	 * @throws FileOpen if the file cannot be created.
	 * @throws FilePath if the path is invalid.
	 */

	void bruteFile(std::string path, std::shared_ptr<Path>& best, std::shared_ptr<std::vector<City>>& cities);

	/**
	 * @brief Reads the input from the "DIST" type input file.
	 *
	 * Reads the input from a file with "DIST" input type. Input type "DIST" means that the file contains matrix with distances between the cities.
	 * @param 	file	Full pathname of the file.
	 * @throws std::invalid_argument if the number of cities is less than 2 or it's not an integer.
	 * @throws FileInput if the data in the matrix is invalid, with the number of the wrong line in the file.
	 * @throws CitiesAmount if there is not enough data.
	 * @throws FileOpen if the file cannot be opened.
	 * @returns Matrix with distances.
	 */

	std::vector<std::vector<double>> readDist(std::string file);

	/**
	 * @brief	Reads the input from the "COORD" type input file.
	 *
	 * Reads the input from a file with "COORD" input type. Input type "COORD" means that the file contains lines with x and y coordinates of each city.
	 * @param 	file Full pathname of the file.
	 * @throws std::invalid_argument if the number of cities is less than 2 or it's not an integer.
	 * @throws FileInput if the coordinates are invalid, with the number of the wrong line in the file.
	 * @throws CitiesAmount if there is not enough data.
	 * @throws FileOpen if the file cannot be opened.
	 * @returns Vector with coordinates of the cities.
	 */

	std::vector<sf::Vector2f> readCoord(std::string file);
}
