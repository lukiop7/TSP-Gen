#include "GUI.h"



GUI::GUI()
{
	window.create(sf::VideoMode(800, 600, 32), "TSP");

	gui.setTarget(window);
	gui.loadWidgetsFromFile("form.txt");

	current_window = gui.get<tgui::ChildWindow>("child1");
	best_window = gui.get<tgui::ChildWindow>("child2");
	open_window = gui.get<tgui::ChildWindow>("open_window");

	current_canvas = tgui::Canvas::create({400, 300});
	current_canvas->clear(sf::Color::White);
	current_window->add(current_canvas);

	best_canvas = tgui::Canvas::create({400, 300});
	best_canvas->clear(sf::Color::White);
	best_window->add(best_canvas);

	city_gen = gui.get<tgui::Button>("citygen");
	start = gui.get<tgui::Button>("Start");
	pause = gui.get<tgui::Button>("Pause");
	stop = gui.get<tgui::Button>("Stop");
	input_button = gui.get<tgui::Button>("input_button");
	open_button = open_window->get<tgui::Button>("open_button");
	output_button = gui.get<tgui::Button>("output_button");

	gen_size = gui.get<tgui::Slider>("GenSize");
	mutation = gui.get<tgui::Slider>("Mutation");
	nb = gui.get<tgui::Slider>("NB");
	type = gui.get<tgui::Slider>("Type");
	selection = gui.get<tgui::Slider>("selection");
	crossover = gui.get<tgui::Slider>("crossover");

	type_text = gui.get<tgui::Label>("Type_text");
	gen_text = gui.get<tgui::Label>("Gen_text");
	mut_text = gui.get<tgui::Label>("Mut_text");
	nb_text = gui.get<tgui::Label>("NB_text");
	shortest = gui.get<tgui::Label>("shortest");
	best = gui.get<tgui::Label>("best");
	current = gui.get<tgui::Label>("current");
	current_best = gui.get<tgui::Label>("current_best");
	selection_text = gui.get<tgui::Label>("selection_text");
	crossover_text = gui.get<tgui::Label>("crossover_text");
	output_text = gui.get<tgui::Label>("output_text");


	input_path = open_window->get<tgui::EditBox>("path_box");
	output_path = gui.get<tgui::EditBox>("output_path");

	file_text = open_window->get<tgui::TextBox>("file_text");

	gui.add(tgui::MessageBox::create("Output", "", {"OK"}), "output_error");
	output_error = gui.get<tgui::MessageBox>("output_error");
	output_error->setEnabled(false);
	output_error->setVisible(false);
	output_error->setPosition({"(&.w - w) / 2", "(&.h - h) / 2"});

	open_window->add(tgui::MessageBox::create("Input", "", {"OK"}), "input_error");
	input_error = open_window->get<tgui::MessageBox>("input_error");
	input_error->setEnabled(false);
	input_error->setVisible(false);
	input_error->setPosition({"(&.w - w) / 2", "(&.h - h) / 2"});

	generated = false;
	performed = false;
	first = true;
	paused = true;


	genetic = nullptr;
	brute = nullptr;

	output_error->connect("ButtonPressed", [&](const std::string& button)
	{
		output_error->setEnabled(false);
		output_error->setVisible(false);
	});

	input_error->connect("ButtonPressed", [&](const std::string& button)
	{
		input_error->setEnabled(false);
		input_error->setVisible(false);
	});

	start->connect("pressed", [&]()
	{
		if (!generated || cities->size() != nb->getValue())
		{
			createCities();
			generated = true;
		}
		if (generated)
		{
			if (type->getValue() == 0)
			{
				brute.reset();
				brute = std::make_unique<BruteForce>(cities);
				brute->bruteForce(current_canvas, best_canvas);
				shortest->setText("Shortest Distance: " + std::to_string(brute->getBest()));
				performed = true;
			}
			else
			{
				if (first == true)
				{
					genetic.reset();
					genetic = std::make_unique<Genetic>(nb->getValue(), gen_size->getValue(), mutation->getValue(),
					                                    cities, selection->getValue(), crossover->getValue());
					first = false;
				}
				paused = false;
				performed = true;
				type->setEnabled(false);
			}
		}
	});
	city_gen->connect("pressed", [&]()
	{
		createCities();
	});
	pause->connect("pressed", [&]()
	{
		if (type->getValue() == 1)
			paused = !paused;
	});
	stop->connect("pressed", [&]()
	{
		first = true;
		paused = true;
		type->setEnabled(true);
	});
	input_button->connect("pressed", [&]()
	{
		open_window->setEnabled(true);
		open_window->setVisible(true);
		input_path->setText("");
		first = true;
		paused = true;
	});
	open_window->connect("closed", [&]()
	{
		open_window->setEnabled(false);
		open_window->setVisible(false);
	});
	open_button->connect("pressed", [&]()
	{
		openFile();
	});
	output_button->connect("pressed", [&]()
	{
		if (performed)
		{
			try
			{
				if (type->getValue() == 0)
					FileIO::bruteFile(output_path->getText(), brute->getBestPath(), cities);
				else
					FileIO::geneticFile(output_path->getText(), genetic->getCntbest(), genetic->getBest(), cities);
			}
			catch (FilePath& e)
			{
				output_error->setText(e.what());
				output_error->setEnabled(true);
				output_error->setVisible(true);
				return;
			}
			catch (FileOpen& e)
			{
				output_error->setText(e.what());
				output_error->setEnabled(true);
				output_error->setVisible(true);
				return;
			}
			catch (std::exception& e)
			{
				output_error->setText(e.what());
				output_error->setEnabled(true);
				output_error->setVisible(true);
				return;
			}
			output_error->setText("Output File Generated");
			output_error->setEnabled(true);
			output_error->setVisible(true);
			return;
		}
		output_error->setText("You must start the algorithm before generating the output!");
		output_error->setEnabled(true);
		output_error->setVisible(true);
	});
}


void GUI::guiShow()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
			gui.handleEvent(event); // Pass the event to the widgets
			updateLabels();
			handleType();
		}
		if (!paused)
			geneticDo();
		window.clear(sf::Color::White);
		gui.draw(); // Draw all widgets

		window.display();
	}
}

void GUI::updateLabels()
{
	nb_text->setText("Number of Cities: " + std::to_string(static_cast<int>(nb->getValue())));
	gen_text->setText("Generation size: " + std::to_string(static_cast<int>(gen_size->getValue())));
	mut_text->setText("Mutation chance: " + std::to_string(mutation->getValue()));
}

void GUI::handleType()
{
	int t = type->getValue();
	switch (t)
	{
	case 0:
		genetic.reset();
		gen_text->setVisible(false);
		gen_size->setVisible(false);
		mutation->setVisible(false);
		selection->setVisible(false);
		crossover->setVisible(false);
		current_best->setVisible(false);
		gen_text->setVisible(false);
		mut_text->setVisible(false);
		current->setVisible(false);
		best->setVisible(false);
		selection_text->setVisible(false);
		crossover_text->setVisible(false);
		nb->setMaximum(10);
		if (brute == nullptr)
			performed = false;
		break;
	case 1:
		brute.reset();
		gen_text->setVisible(true);
		gen_size->setVisible(true);
		mutation->setVisible(true);
		selection->setVisible(true);
		crossover->setVisible(true);
		current_best->setVisible(true);
		nb->setMaximum(50);
		gen_text->setVisible(true);
		mut_text->setVisible(true);
		current->setVisible(true);
		best->setVisible(true);
		selection_text->setVisible(true);
		crossover_text->setVisible(true);
		if (genetic == nullptr)
			performed = false;
		break;
	}
}

void GUI::openFile()
{
	try
	{
		auto line = FileIO::checkFile(input_path->getText());
		std::string token;
		std::stringstream iss;
		iss << line;
		getline(iss, token, ';');
		if (token == "COORD")
		{
			std::vector<sf::Vector2f> input(0);
			input = FileIO::readCoord(input_path->getText());
			if (!input.empty())
			{
				if (input.size() > 10)
				{
					type->setValue(1);
					handleType();
				}
				nb->setValue(input.size());
				createCities(input);
				open_window->setEnabled(false);
				open_window->setVisible(false);
			}
		}
		else if (token == "DIST")
		{
			std::vector<std::vector<double>> input(0);
			input = FileIO::readDist(input_path->getText());
			if (!input.empty())
			{
				if (input.size() > 10)
				{
					type->setValue(1);
					handleType();
				}
				nb->setValue(input.size());
				createCities(input);
				open_window->setEnabled(false);
				open_window->setVisible(false);
			}
		}
		else
			throw InputType();
	}

	catch (FilePathExt& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (FileInput& e)
	{
		input_error->setText(e.message());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (FileOpen& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (CitiesAmount& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (InputType& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (std::invalid_argument& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
	catch (std::exception& e)
	{
		input_error->setText(e.what());
		input_error->setVisible(true);
		input_error->setEnabled(true);
	}
}

void GUI::createCities()
{
	cities.reset();
	int size = nb->getValue();
	cities = std::make_shared<std::vector<City>>();
	for (int i = 0; i < size; i++)
	{
		City tmp(randomize(), randomize(), i, size); //randomized version
		cities->push_back(tmp);
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cities->at(i).getDistances()[j] = cities->at(i).distanceTo(cities->at(j));
			//calculate distances to each city 
		}
	}
	generated = true;
}

void GUI::createCities(std::vector<std::vector<double>> input)
{
	cities.reset();
	int size = nb->getValue();
	cities = std::make_shared<std::vector<City>>();

	sf::CircleShape coords;
	coords.setPosition(200, 150);
	coords.setRadius(145);
	coords.setOrigin(coords.getRadius(), coords.getRadius());
	coords.setPointCount(size);

	std::map<double, int> sort_map;
	for (int i = 0; i < size; ++i)
		sort_map[input[0][i]] = i;

	std::vector<sf::Vector2f> coordinates(size);
	int cnt = 0;

	for (auto it = sort_map.begin(); it != sort_map.end(); ++it)
	{
		coordinates[it->second] = coords.getPoint(cnt++);
		coordinates[it->second].x += 50;
		coordinates[it->second].y += 5;
	}

	for (int i = 0; i < size; i++)
	{
		City tmp(input[i], coordinates[i], i, size);
		cities->push_back(tmp);
	}
	generated = true;
}

void GUI::createCities(std::vector<sf::Vector2f> input)
{
	cities.reset();
	int size = nb->getValue();
	cities = std::make_shared<std::vector<City>>();
	for (int i = 0; i < size; i++)
	{
		auto crd = input[i];
		City tmp(crd, i, size);
		cities->push_back(tmp);
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cities->at(i).getDistances()[j] = cities->at(i).distanceTo(cities->at(j));
			//calculate distances to each city 
		}
	}
	generated = true;
}

void GUI::geneticDo()
{
	if (!paused)
	{
		genetic->geneticAlgorithm();
		genetic->displayAll(current_canvas, best_canvas);
		best->setText("Best Generation: " + std::to_string(genetic->getCntbest()));
		current->setText("Current Generation: " + std::to_string(genetic->getCnt()));
		shortest->setText("Shortest Distance: " + std::to_string(genetic->getShortest()));
		current_best->setText("Current Best: " + std::to_string(genetic->getCurrentShortest()));
	}
}

double GUI::randomize()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_real_distribution<double> distr(50, 250); // define the range
	return distr(eng);
}
