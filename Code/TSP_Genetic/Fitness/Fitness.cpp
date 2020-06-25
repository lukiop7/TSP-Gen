#include "Fitness.h"

void Fitness::calculateFitness(std::unique_ptr<Generation>& generation)
{
	for (int i = 0; i < generation->getSize(); i++)
	{
		generation->getPaths()[i].setFitness(1 / generation->getPaths()[i].getDistance());
	}
	std::sort(generation->getPaths().begin(), generation->getPaths().end(), std::greater<Path>());
}
