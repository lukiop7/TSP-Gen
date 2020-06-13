#include "Tournament.h"

std::pair<Path, Path> Tournament::selection(std::unique_ptr<Generation>& generation)
{
	std::set<int> numbers, numbers2;
	while (numbers.size() != 4)
	{
		numbers.insert(randomize(generation->getSize()));
		numbers2.insert(randomize(generation->getSize()));
	}
	auto it = numbers.begin();
	//because generation is sorted by fitness i can just take the lowest indexes from the set.
	auto it2 = numbers2.begin();
	//because generation is sorted by fitness i can just take the lowest indexes from the set.
	int p1 = *it;
	int p2 = *it2;
	return std::pair<Path, Path>(generation->getPaths()[p1], generation->getPaths()[p2]);
}

int Tournament::randomize(int size)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, size - 1); // define the range
	return distr(eng);
}
