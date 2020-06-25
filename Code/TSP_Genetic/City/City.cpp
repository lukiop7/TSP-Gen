#include "City.h"

#include <iostream>

City::City(std::vector<double> dist, sf::Vector2f coords, int _id, int n): id(_id)
{
	x = coords.x;
	y = coords.y;
	for (int i = 0; i < n; i++)
	{
		distances.push_back(dist[i]);
	}
}

double City::distanceTo(City& a)
{
	if (a.getX() == this->x && a.getY() == this->y)
	{
		return 0;
	}
	int x_tmp = abs(this->x - a.getX());
	int y_tmp = abs(this->y - a.getY());
	x_tmp *= x_tmp;
	y_tmp *= y_tmp;
	double distance = sqrt(x_tmp + y_tmp);
	return distance;
}


int City::getId() const
{
	return id;
}

double City::getX() const
{
	return x;
}

std::vector<double>& City::getDistances()
{
	return distances;
}

double City::getY() const
{
	return y;
}
