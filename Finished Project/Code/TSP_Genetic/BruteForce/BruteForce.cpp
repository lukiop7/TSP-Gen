#include "BruteForce.h"

BruteForce::BruteForce(std::shared_ptr<std::vector<City>>& c): cities_amount(c->size())
{
	best = INFINITY;
	cities = c;
}

void BruteForce::permutations()
{
	std::vector<int> index;
	for (int i = 0; i < cities_amount; i++)
		index.push_back(i);
	int ind = cities_amount;
	for (int i = 0; i < ind; i++)
	{
		index[i] = i;
	}
	int cnt = -1;
	do
	{
		Path tmp(ind);
		for (int i = 0; i < ind; i++)
		{
			tmp.addCity(cities->at(index[i]));
		}

		paths.push_back(tmp);
		cnt++;
		if (paths[cnt].getDistance() < best)
		{
			best = paths[cnt].getDistance();
			best_path = std::make_shared<Path>(paths[cnt]);
			index_best = cnt;
		}
	}
	while (std::next_permutation(index.begin(), index.end()));
}


void BruteForce::displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2)
{
	sf::VertexArray lines(sf::LinesStrip, cities_amount);
	sf::CircleShape tmp;
	tmp.setRadius(3);
	tmp.setFillColor(sf::Color::Black);


	canvas1->clear(sf::Color::White);
	for (int j = 0; j < cities_amount; j++)
	{
		tmp.setPosition(sf::Vector2f(paths[0].getCities()[j].getX() - 3, paths[0].getCities()[j].getY() - 3));
		lines[j].position = sf::Vector2f(paths[0].getCities()[j].getX(), paths[0].getCities()[j].getY());
		lines[j].color = sf::Color::Black;
		canvas1->draw(tmp);
	}

	canvas1->draw(lines);

	canvas1->display();

	canvas2->clear(sf::Color::White);
	for (int j = 0; j < cities_amount; j++)
	{
		lines[j].position = sf::Vector2f(paths[index_best].getCities()[j].getX(),
		                                 paths[index_best].getCities()[j].getY());
		tmp.setPosition(sf::Vector2f(paths[index_best].getCities()[j].getX() - 3,
		                             paths[index_best].getCities()[j].getY() - 3));
		canvas2->draw(tmp);
	}

	canvas2->draw(lines);

	canvas2->display();
}

void BruteForce::bruteForce(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2)
{
	permutations();
	displayAll(canvas1, canvas2);
}

double BruteForce::getBest() const
{
	return best;
}

std::shared_ptr<Path>& BruteForce::getBestPath()
{
	return best_path;
}
