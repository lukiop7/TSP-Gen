#include "FileIO.h"

namespace FileIO
{
	std::string checkFile(std::string path)
	{
		std::regex check(R"(^(?:[\w]:|\\)(\\[A-Z a-z_\s0-9.-]+)+\.(txt|csv)$)");
		if (!path.empty())
		{
			if (std::regex_match(path, check))
			{
				std::ifstream sample(path);
				std::string line;
				std::getline(sample, line);
				sample.close();
				return line;
			}
			throw FilePathExt();
		}

		throw FileOpen();
	}

	void geneticFile(std::string path, int number, std::shared_ptr<Path>& best,
	                 std::shared_ptr<std::vector<City>>& cities)
	{
		std::regex check(R"(^(?:[\w]:|\\)(\\[A-Z a-z_\s0-9.-]+)*\\{0,1}$)");
		if (!path.empty())
		{
			if (std::regex_match(path, check))
			{
				path += "\\" + std::to_string(number) + ".txt";
				std::ofstream output(path);
				if (output.is_open())
				{
					output << "Generation Number: " << number << std::endl;
					output << "Shortest distance: " << best->getDistance() << std::endl;
					output << "Shortest Path: ";
					for (auto& x : best->getCities())
					{
						output << x.getId() << "->";
					}
					output << best->getCities()[0].getId();
					output << std::endl;
					output << "Number of Cities: "<<best->getMax()<<std::endl;
					output << "Cities: \n";
					output << "FORMAT:  x ; y ;\n\n";
					for (auto& x : *cities)
					{
						output << x.getX() << " ; " << x.getY() << " ; \n";
					}
					output << "\nDISTANCES BETWEEN CITIES: \n\n";
					for (auto& x : *cities)
					{
						output << " ";
						for (auto& y : x.getDistances())
						{
							output << std::fixed;
							output << std::setprecision(4);
							output << y << " ; ";
						}
						output << std::endl;
					}
					output.close();
					return;
				}

				throw FileOpen();
			}
			throw FilePath();
		}
	}

	void bruteFile(std::string path, std::shared_ptr<Path>& best, std::shared_ptr<std::vector<City>>& cities)
	{
		std::regex check(R"(^(?:[\w]:|\\)(\\[A-Z a-z_\s0-9.-]+)*\\{0,1}$)");
		if (!path.empty())
		{
			if (std::regex_match(path, check))
			{
				path += "\\BruteForce.txt";
				std::ofstream output(path);
				if (output.is_open())
				{
					output << "Brute Force solution\n";
					output << "Shortest distance: " << best->getDistance() << std::endl;
					output << "Shortest Path: ";
					for (auto& x : best->getCities())
					{
						output << x.getId() << "->";
					}
					output << best->getCities()[0].getId();
					output << std::endl;
					output << "Number of Cities: " << best->getMax() << std::endl;
					output << "Cities: \n";
					output << "FORMAT:  x ; y ;\n\n";
					for (auto& x : *cities)
					{
						output  << x.getX() << " ; " << x.getY() << " ; \n";
					}
					output << "\nDISTANCES BETWEEN CITIES: \n\n";
					for (auto& x : *cities)
					{
						output << " ";
						for (auto& y : x.getDistances())
						{
							output << std::fixed;
							output << std::setprecision(4);
							output << y << " ; ";
						}
						output << std::endl;
					}
					output.close();
					return;
				}

				throw FileOpen();
			}
			throw FilePath();
		}
	}

	std::vector<std::vector<double>> readDist(std::string file)
	{
		std::ifstream sample(file);
		double size;
		std::string line;
		int i = 0;
		if (sample.is_open())
		{
			std::regex check(R"( ?[^\w\D]*((0\.0*)|([1-9][0-9]*\.[0-9]*)) ?;?)");
			std::string tmp;
			std::getline(sample, tmp);
			std::getline(sample, tmp);
			size = std::stof(tmp);
			if (size < 2)
			{
				sample.close();
				throw std::invalid_argument("INVALID INPUT - INVALID SIZE");
			}
			std::vector<std::vector<double>> input(size, std::vector<double>(size));
			while (getline(sample, line) && i < size)
			{
				auto words_begin =
					std::sregex_iterator(line.begin(), line.end(), check);
				auto words_end = std::sregex_iterator();
				if (std::distance(words_begin, words_end) != size)
				{
					sample.close();
					throw FileInput(i + 3);
				}
				std::string token;
				std::stringstream iss;
				int j = 0;
				iss << line;
				while (getline(iss, token, ';') && j < size)
				{
					input[i][j++] = std::stof(token);
				}
				iss.clear();
				if (j != size)
					throw CitiesAmount();
				++i;
			}
			if (i != size)
				throw CitiesAmount();
			sample.close();
			return input;
		}

		throw FileOpen();
	}

	std::vector<sf::Vector2f> readCoord(std::string file)
	{
		std::ifstream sample(file);
		double size;
		std::string line;
		int i = 0;
		if (sample.is_open())
		{
			std::string tmp;
			std::regex check(R"(^([1-3]?[\d]{1,2}.[\d]+) *;{1} *([1-2]?[\d]{1,2}.[\d]+) *;\s?$)");
			std::getline(sample, tmp);
			std::getline(sample, tmp);
			size = std::stof(tmp);
			if (size < 2 || size>50)
			{
				sample.close();
				throw std::invalid_argument("INVALID INPUT - INVALID SIZE");
			}
			std::vector<sf::Vector2f> input(size);
			while (getline(sample, line) && i < size)
			{
				if (!std::regex_match(line, check))
				{
					sample.close();
					throw FileInput(i + 3);
				}
				std::string token;
				std::stringstream iss;
				iss << line;

				getline(iss, token, ';');
				input[i].x = std::stof(token);

				getline(iss, token, ';');
				input[i].y = std::stof(token);

				iss.clear();
				++i;
			}
			if (i != size)
				throw CitiesAmount();
			sample.close();
			return input;
		}
		throw FileOpen();
	}
}
