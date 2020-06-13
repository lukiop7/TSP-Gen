#include "Two_Points.h"



void TwoPoints::twoCross(Path& child, std::pair<int, int> border, Path p1, Path p2)
{
	int j = 0;
	int size = p1.getMax();
	for (int i = 0; i < size; i++)
	{
		if (i <= border.first || i >= border.second)
		{
			child.addCity(p1.getCities()[i]);
		}
		else
		{
			if (helpers::contains(p1.getCities(), border, p2.getCities()[i]))
			{
				if (j <= border.first)
				{
					while (helpers::contains(p1.getCities(), border, p2.getCities()[j]) && j <= border.first)
					{
						j++;
					}
					if (j > border.first)
						j = border.second;
				}
				if (j >= border.second)
				{
					while (helpers::contains(p1.getCities(), border, p2.getCities()[j]) && j < size)
					{
						j++;
					}
				}
				child.addCity(p2.getCities()[j++]);
				if (j > border.first && j < border.second)
					j = border.second;
			}
			else
			{
				child.addCity(p2.getCities()[i]);
			}
		}
	}
}

std::pair<Path, Path> TwoPoints::cross(std::pair<Path, Path>& parents_pair)
{
	Path child1(parents_pair.first.getMax()), child2(parents_pair.first.getMax());
	std::pair<int, int> border = randomize(parents_pair.first.getMax());
	twoCross(child1, border, parents_pair.first, parents_pair.second);
	twoCross(child2, border, parents_pair.second, parents_pair.first);
	return std::pair<Path, Path>(child1, child2);
}

std::pair<int, int> TwoPoints::randomize(int size)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr1(0, size - 3);
	// to guarantee that there will be 2 elements: 1 between borders , 1 for second border
	int border1 = distr1(eng);
	std::uniform_int_distribution<> distr2(border1 + 2, size - 1); // second border from border1 +2 to end of the vector
	int border2 = distr2(eng);
	return std::pair<int, int>(border1, border2);
}
