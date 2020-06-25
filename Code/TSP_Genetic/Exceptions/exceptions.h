/**
 * @file	TSP_Genetic\exceptions.h.
 *
 * @brief	Contains custom exception classes.
 */

#pragma once
#include <exception>

/**@class FilePathExt
 *@brief Responsible for throwing a message when the path or extension of the file is invalid.  */

class FilePathExt : public std::exception
{
public:

	/**
	 * @brief	Gets the message
	 *
	 * @returns	Null if it fails, else a pointer to a const char.
	 */

	const char* what() const throw () override
	{
		return "INVALID PATH OR EXTENSION";
	}
};

/**@class FilePath
 *@brief	Responsible for throwing a message when the path of the file is invalid.*/

class FilePath : public std::exception
{
public:

	/**
	 * @brief	Gets the message
	 *
	 * @returns	Null if it fails, else a pointer to a const char.
	 */

	const char* what() const throw () override
	{
		return "INVALID PATH";
	}
};

/**@class FileInput
 *@brief	Responsible for throwing a message when the data in the file is invalid.*/

class FileInput : public std::exception
{
public:

	/**
	 * @brief	Constructor
	 *
	 * @param 	i	Number of the line containing incorrect input.
	 */

	FileInput(int i): line(i)
	{
		msg = "INVALID INPUT LINE " + std::to_string(line);
	}

	/**
	 * @brief	Gets the message
	 *
	 * @returns	A reference to a const std::string.
	 */

	const std::string& message()
	{
		return msg;
	}

private:
	/** @brief	Number of the line */
	int line;
	/** @brief	The message */
	std::string msg;
};

/**@class FileOpen
 *@brief	Responsible for throwing a message when the file cannot be opened or created.*/

class FileOpen : public std::exception
{
public:

	/**
	 * @brief	Gets the message
	 *
	 * @returns	Null if it fails, else a pointer to a const char.
	 */

	const char* what() const throw () override
	{
		return "CANNOT OPEN THE FILE";
	}
};

/**@class InputType
 *@brief	Responsible for throwing a message when the line informing about the input type of the file is incorrect.*/
class InputType : public std::exception
{
public:

	/**
	 * @brief	Gets the message
	 *
	 * @returns	Null if it fails, else a pointer to a const char.
	 */

	const char* what() const throw () override
	{
		return "SPECIFY INPUT TYPE - DIST OR COORD";
	}
};


/**@class CitiesAmount
 *@brief	Responsible for throwing a message when there is not enough data for declared number of cities.*/

class CitiesAmount : public std::exception
{
public:

	/**
	 * @brief	Gets the message
	 *
	 * @returns	Null if it fails, else a pointer to a const char.
	 */

	const char* what() const throw () override
	{
		return "Not enough data for declared size";
	}
};
