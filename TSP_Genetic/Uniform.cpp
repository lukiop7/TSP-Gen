#include "Uniform.h"
#include "helpers.h"


void Uniform::uniformCross(Path& child, Path& p1, Path& p2)
{
	std::vector<Path> parents = {p1, p2};

	int size = p1.getMax();

	std::set<City> unused;
	bool need = false;

	for (int i = 0; i < size; ++i)
	{
		int decision = randomize();

		if (helpers::contains(child.getCities(), parents[decision].getCities()[i]))
			if (helpers::contains(child.getCities(), parents[!decision].getCities()[i]))
				need = true;
			else
			{
				child.addCity(parents[!decision].getCities()[i]);
				unused.erase(parents[!decision].getCities()[i]);
			}
		else
		{
			child.addCity(parents[decision].getCities()[i]);
			unused.erase(parents[decision].getCities()[i]);
			if (!helpers::contains(child.getCities(), parents[!decision].getCities()[i]))
				unused.insert(parents[!decision].getCities()[i]);
		}
		if (need)
		{
			child.addCity(*unused.begin());
			unused.erase(unused.begin());
			need = false;
		}
	}
}

std::pair<Path, Path> Uniform::cross(std::pair<Path, Path>& parents_pair)
{
	Path child1(parents_pair.first.getMax()), child2(parents_pair.first.getMax());
	uniformCross(child1, parents_pair.first, parents_pair.second);
	uniformCross(child2, parents_pair.first, parents_pair.second);
	return std::pair<Path, Path>(child1, child2);
}

int Uniform::randomize()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 1);
	// to guarantee that there will be 2 elements: 1 between borders , 1 for second border
	return distr(eng);
}
