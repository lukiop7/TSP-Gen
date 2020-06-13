#include "Path.h"

Path::Path(const Path& p)
{
	amount = p.amount;
	max = p.max;
	complete = p.complete;
	cities = p.cities;
	distance = p.distance;
	fitness = p.fitness;
}

void Path::addCity(City city)
{
	if (amount != max)
	{
		cities.push_back(city);
		amount += 1;
	}
	if (amount == max)
	{
		checkDistance();
		complete = true;
	}
}

int Path::getMax() const
{
	return max;
}


std::vector<City>& Path::getCities()
{
	return cities;
}

double Path::getDistance() const
{
	return distance;
}

void Path::setCities(std::vector<City> cities)
{
	this->cities = cities;
}

void Path::checkDistance()
{
	distance = 0;
	for (int i = 0; i < max - 1; i++)
	{
		distance += cities[i].getDistances()[cities[i + 1].getId()];
	}
	distance += cities.back().getDistances()[cities[0].getId()];
}


double Path::getFitness() const
{
	return fitness;
}

void Path::setFitness(double fitness)
{
	this->fitness = fitness;
}
