#include "Single_Point.h"

#include "helpers.h"

void SinglePoint::singleCross(Path& child, int border, Path p1, Path p2)
{
	int j = 0;
	for (int i = 0; i < p1.getMax(); i++)
	{
		if (i <= border)
		{
			child.addCity(p1.getCities()[i]);
		}
		else
		{
			if (helpers::contains(p1.getCities(), border, p2.getCities()[i]))
			{
				while (helpers::contains(p1.getCities(), border, p2.getCities()[j]) && j <= border)
				{
					j++;
				}
				child.addCity(p2.getCities()[j]);
				j++;
			}
			else
			{
				child.addCity(p2.getCities()[i]);
			}
		}
	}
}

std::pair<Path, Path> SinglePoint::cross(std::pair<Path, Path>& parents_pair)
{
	Path child1(parents_pair.first.getMax()), child2(parents_pair.first.getMax());
	int border = randomize(parents_pair.first.getMax());
	singleCross(child1, border, parents_pair.first, parents_pair.second);
	singleCross(child2, border, parents_pair.second, parents_pair.first);
	return std::pair<Path, Path>(child1, child2);
}

int SinglePoint::randomize(int size)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, size - 2); // to guarantee that there will be at least one element 
	return distr(eng);
}
