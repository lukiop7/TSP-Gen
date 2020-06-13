#include "Mutation.h"

Mutation::Mutation(double r): ratio(r)
{
}

Mutation::~Mutation()
{
}

void Mutation::mutate(std::unique_ptr<Generation>& generation)
{
	if (ratio != 0)
	{
		for (int i = 0; i < generation->getSize(); i++)
		{
			if (randomize(0, 1) <= ratio)
			{
				int tmp1 = randomize(0, generation->getCitiesnb() - 1);
				int tmp2 = randomize(0, generation->getCitiesnb() - 1);
				while (tmp1 == tmp2)
					tmp2 = randomize(0, generation->getCitiesnb());
				std::swap(generation->getPaths()[i].getCities()[tmp1], generation->getPaths()[i].getCities()[tmp2]);
				generation->getPaths()[i].checkDistance();
			}
		}
	}
}

double Mutation::randomize(int i, int j)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_real_distribution<> distr(i, j); // define the range
	return distr(eng);
}
