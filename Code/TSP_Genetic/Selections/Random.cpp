#include "Random.h"


std::pair<Path, Path> Random::selection(std::unique_ptr<Generation>& generation)
{
	auto p1 = randomize(generation->getSize());
	auto p2 = randomize(generation->getSize());
	while (p2 == p1)
		p1 = randomize(generation->getSize());

	return std::pair<Path, Path>(generation->getPaths()[p1], generation->getPaths()[p2]);
}

int Random::randomize(int size)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, size - 1); // define the range
	return distr(eng);
}
