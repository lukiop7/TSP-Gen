#include "Route_Wheel.h"

std::pair<Path, Path> Route_Wheel::selection(std::unique_ptr<Generation>& generation)
{
	std::vector<double> wheel;
	double sum = 0.0;
	for (auto& x : generation->getPaths())
	{
		sum += x.getFitness();
	}
	for (auto& x : generation->getPaths())
	{
		double tmp = (x.getFitness() / sum);
		wheel.push_back(tmp);
	}
	int p1 = pickFromWheel(wheel);
	int p2 = pickFromWheel(wheel);
	while (p1 == p2)
		p2 = pickFromWheel(wheel);
	return std::pair<Path, Path>(generation->getPaths()[p1], generation->getPaths()[p2]);
}

int Route_Wheel::pickFromWheel(std::vector<double> wheel)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::discrete_distribution<> d(wheel.begin(), wheel.end());
	return d(gen);
}
