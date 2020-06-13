#include "Generation.h"

Generation::Generation(int cs, int s, std::shared_ptr<std::vector<City>>& c): generation_counter(0), cities_nb(cs),
                                                                              size(s)
{
	cities = c;
	best = INFINITY;
	current_best = INFINITY;
}

void Generation::generate()
{
	std::vector<City> tmp_cities;
	int cit_size = cities->size();
	for (int x = 0; x < cit_size; ++x)
	{
		tmp_cities.push_back(cities->at(x));
	}

	for (int i = 0; i < size; ++i)
	{
		std::random_shuffle(tmp_cities.begin(), tmp_cities.end());

		Path tmp(tmp_cities.size());
		for (size_t x = 0; x < cities->size(); ++x)
		{
			tmp.addCity(tmp_cities[x]);
		}

		paths.push_back(tmp);
	}
}

void Generation::displayAll(tgui::Canvas::Ptr canvas1, tgui::Canvas::Ptr canvas2)
{
	sf::VertexArray lines(sf::LinesStrip, cities_nb);
	sf::CircleShape tmp;
	tmp.setRadius(3);
	tmp.setFillColor(sf::Color::Black);


	canvas1->clear(sf::Color::White);
	for (int j = 0; j < cities_nb; j++)
	{
		tmp.setPosition(sf::Vector2f(best_current->getCities()[j].getX() - 3,
		                             best_current->getCities()[j].getY() - 3));
		lines[j].position = sf::Vector2f(best_current->getCities()[j].getX(), best_current->getCities()[j].getY());
		lines[j].color = sf::Color::Black;
		canvas1->draw(tmp);
	}

	canvas1->draw(lines);

	canvas1->display();


	canvas2->clear(sf::Color::White);
	for (int j = 0; j < cities_nb; ++j)
	{
		lines[j].position = sf::Vector2f(best_path->getCities()[j].getX(), best_path->getCities()[j].getY());
		tmp.setPosition(sf::Vector2f(best_path->getCities()[j].getX() - 3, best_path->getCities()[j].getY() - 3));
		canvas2->draw(tmp);
	}

	canvas2->draw(lines);

	canvas2->display();
	current_best = INFINITY;
}

int Generation::getCounter() const
{
	return generation_counter;
}

void Generation::setCounter(int counter)
{
	this->generation_counter = counter;
}

const int Generation::getCitiesnb() const
{
	return cities_nb;
}


const int Generation::getSize() const
{
	return size;
}


double Generation::getBest() const
{
	return best;
}

double Generation::getCurrentBest() const
{
	return best_current->getDistance();
}

int Generation::getCntbest() const
{
	return cnt_best;
}


std::shared_ptr<std::vector<City>> Generation::getCities() const
{
	return cities;
}


std::vector<Path>& Generation::getPaths()
{
	return paths;
}

void Generation::setPaths(std::vector<Path> paths)
{
	this->paths = paths;
}

void Generation::checkBest()
{
	for (int i = 0; i < size; ++i)
	{
		if (paths[i].getDistance() < current_best)
		{
			best_current = std::make_shared<Path>(paths[i]);
			current_best = paths[i].getDistance();
			if (paths[i].getDistance() < best)
			{
				best_path = std::make_shared<Path>(paths[i]);
				best = best_path->getDistance();
				cnt_best = generation_counter;
			}
		}
	}
}

std::shared_ptr<Path>& Generation::getBestPath()
{
	return best_path;
}
