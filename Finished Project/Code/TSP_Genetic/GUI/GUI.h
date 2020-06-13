/**
 * @file	TSP_Genetic\GUI.h.
 *
 * @brief	Declares the graphical user interface class
 */

#pragma once
#include <TGUI/TGUI.hpp>
#include <regex>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "../BruteForce/BruteForce.h"
#include "../Genetic/Genetic.h"
#include "../Exceptions/exceptions.h"
#include "../FileIO/FileIO.h"

/** @class GUI
 *@brief	Graphical User Interface.
*
* Class responsible for GUI. GUI is created using TGUI library.
* Contains pointers to BruteForce and Genetic classes. 
* Also creates cities that will be used in TSP.
 */

class GUI
{
public:

	/** @brief	GUI constructor.        
	*
	* Loads TGUI widgets from txt file. Handles button signals. 
	*/

	GUI();

	/** @brief	Shows The gui.  
	 * 
	 * Contains main GUI loop. Responsible for detecting events, passing them to the widgets and displaying the interface.
	 */

	void guiShow();
private:
	/** @brief	The render window */
	sf::RenderWindow window;
	/** @brief	The graphical user interface */
	tgui::Gui gui;
	/** @brief	Current path window */
	tgui::ChildWindow::Ptr current_window;
	/** @brief	Best path window */
	tgui::ChildWindow::Ptr best_window;
	/** @brief	Input file window */
	tgui::ChildWindow::Ptr open_window;
	/** @brief	Generate Cities button */
	tgui::Button::Ptr city_gen;
	/** @brief	Start Button */
	tgui::Button::Ptr start;
	/** @brief	Pause Button */
	tgui::Button::Ptr pause;
	/** @brief	Stop button */
	tgui::Button::Ptr stop;
	/** @brief	Open file button */
	tgui::Button::Ptr open_button;
	/** @brief	Input file button */
	tgui::Button::Ptr input_button;
	/** @brief	Output file button */
	tgui::Button::Ptr output_button;
	/** @brief	The current canvas */
	tgui::Canvas::Ptr current_canvas;
	/** @brief	The best canvas */
	tgui::Canvas::Ptr best_canvas;
	/** @brief	Generation size slider */
	tgui::Slider::Ptr gen_size;
	/** @brief	Mutation slider */
	tgui::Slider::Ptr mutation;
	/** @brief	Number of cities slider */
	tgui::Slider::Ptr nb;
	/** @brief	Solution type slider
	 *
	 * Slider values:
	 * 0 - brute force.
	 * 1 - genetic algorithm.
	 */
	tgui::Slider::Ptr type;
	/** @brief	Selection method slider */
	tgui::Slider::Ptr selection;
	/** @brief	Crossover method slider */
	tgui::Slider::Ptr crossover;
	/** @brief	The type text */
	tgui::Label::Ptr type_text;
	/** @brief	The generate text */
	tgui::Label::Ptr gen_text;
	/** @brief	The mutation text */
	tgui::Label::Ptr mut_text;
	/** @brief	The number text */
	tgui::Label::Ptr nb_text;
	/** @brief	The shortest text */
	tgui::Label::Ptr shortest;
	/** @brief	The best */
	tgui::Label::Ptr best;
	/** @brief	The current */
	tgui::Label::Ptr current;
	/** @brief	The current best */
	tgui::Label::Ptr current_best;
	/** @brief	The selection text */
	tgui::Label::Ptr selection_text;
	/** @brief	The crossover text */
	tgui::Label::Ptr crossover_text;
	/** @brief	The output text */
	tgui::Label::Ptr output_text;
	/** @brief	Full pathname of the input file */
	tgui::EditBox::Ptr input_path;
	/** @brief	Full pathname of the output file */
	tgui::EditBox::Ptr output_path;;
	/** @brief	The file text */
	tgui::TextBox::Ptr file_text;
	/** @brief	Messagebox for output file */
	tgui::MessageBox::Ptr output_error;
	/** @brief	Messagebox for input file */
	tgui::MessageBox::Ptr input_error;

	/** @brief	Updates the labels displaying values of the sliders.
	 *
	 * Changes the texts in labels to show values of the sliders(number of cities etc.).
	 */

	void updateLabels();

	/** @brief	Handles the type of the solution
	 *
	 * Changes visibility of the GUI elements depending on the type of the solution.
	 */

	void handleType();

	/** @brief	Pointer to the brute force class*/
	std::unique_ptr<BruteForce> brute;
	/** @brief	Pointer to the genetic algorithm class */
	std::unique_ptr<Genetic> genetic;
	/** @brief	Pointer to the vector with cities*/
	std::shared_ptr<std::vector<City>> cities;

	/** @brief	Opens and reads the input file
	 * 
	 * Uses functions from FileIO namespace.
	 * @throws InputType Thrown if the input data type description in the file is incorrect.
	 */

	void openFile();

	/** @brief	 Creates cities with random x and y coordinates.
	 * 
	 *
	 */

	void createCities();

	/**
	 * @brief	Creates the cities from the file input using vectors containing distances between the cities.
	 *		
	 * @param 	input	Distances between the cities.
	 */

	void createCities(std::vector<std::vector<double>> input);

	/**
	 * @brief	Creates the cities from the file input using vector of x and y coordinates of each city.
	 *
	 * @param 	input	x and y coordinates of each city.
	 */

	void createCities(std::vector<sf::Vector2f> input);

	/** @brief	Performs genetic algorithm
	 * 
	 * Calls functions form the genetic class and updates labels connected with the algorithm. 
	 */

	void geneticDo();

	/**
	 * @brief	 Generates random number in a range. 
	 *
	 *
	 *Used to generate coordinates of the cities.
	 * @returns	Random number.
	 */

	double randomize();

	/** @brief	True if cities were generated */
	bool generated;
	/** @brief	True if start button was clicked */
	bool performed;
	/** @brief	True if it will be the first generation of the algorithm*/
	bool first;
	/** @brief	True if paused */
	bool paused;
};
