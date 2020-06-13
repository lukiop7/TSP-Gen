#include "Genetic.h"

Genetic::Genetic(int c, int s, double r, std::shared_ptr<std::vector<City>>& cit, int sel_strat, int cross_strat):
	gen_size(s),
	mut_ratio(r),
	gen_counter(0)
{
	cities = cit;
	generation = std::make_unique<Generation>(c, s, cities);
	mutation_strategy = std::make_unique<Mutation>(mut_ratio);
	fitness_strategy = std::make_unique<Fitness>();
	switch (sel_strat)
	{
	case 0:
		selection_strategy = std::make_unique<Route_Wheel>();
		break;
	case 1:
		selection_strategy = std::make_unique<Tournament>();
		break;
	case 2:
		selection_strategy = std::make_unique<Random>();
	}
	switch (cross_strat)
	{
	case 0:
		crossover_strategy = std::make_unique<SinglePoint>();
		break;
	case 1:
		crossover_strategy = std::make_unique<TwoPoints>();
		break;
	case 2:
		crossover_strategy = std::make_unique<Uniform>();
	}
}


void Genetic::geneticAlgorithm()
{
	if (gen_counter != 0)
	{
		fitness_strategy->calculateFitness(generation);
		std::vector<Path> new_gen;
		while (new_gen.size() != gen_size)
		{
			auto parents = selection_strategy->selection(generation);
			auto children = crossover_strategy->cross(parents);
			new_gen.push_back(children.first);
			new_gen.push_back(children.second);
		}
		generation->setPaths(new_gen);
		mutation_strategy->mutate(generation);
		gen_counter++;
		generation->setCounter(gen_counter);
		generation->checkBest();
		best_path = generation->getBestPath();
		cnt_best = generation->getCntbest();
		shortest_distance = generation->getBest();
		current_shortest = generation->getCurrentBest();
	}
	else
	{
		generate();
		fitness_strategy->calculateFitness(generation);
		generation->checkBest();
		cnt_best = generation->getCntbest();
		shortest_distance = generation->getBest();
		gen_counter++;
		generation->setCounter(gen_counter);
	}
}

void Genetic::displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2)
{
	generation->displayAll(canvas1, canvas2);
}

int Genetic::getCntbest() const
{
	return cnt_best;
}

int Genetic::getCnt() const
{
	return gen_counter;
}

double Genetic::getShortest() const
{
	return shortest_distance;
}

double Genetic::getCurrentShortest() const
{
	return generation->getCurrentBest();
}

std::shared_ptr<Path>& Genetic::getBest()
{
	return best_path;
}

void Genetic::generate()
{
	generation->generate();
}
