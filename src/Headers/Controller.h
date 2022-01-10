#pragma once
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Model.h"
#include "Randomiser.h"

class Controller
{
private:
	unsigned short state = 0;  // current state of the game; 0 - menu, 1 - game, 2 - pause
	sf::RenderWindow *_window; // pointer to the window
	Model model;
	sf::View view;
	std::vector<sf::Sprite> sprites;
	bool current_background_inidicator = 0;
	bool single_pressed = 0;
	bool is_upward = 0;

	sf::Sprite current_background;
	sf::Clock gravity_clock;
	sf::Time elapsed;

	const float gravity_force = 200;
	const float initial_gravity_boost = 5;
	const float space_kick = 15; // kick kick kick!!!!!!!!!!!
	float delta_s = 0, upward_force = 0;

	Randomiser randomiser;
	unsigned int starting_dist = 500, max_height, min_height = 50;
	float gap_height, gap_width, last_dist;

	sf::Font arial;
	sf::Text points;

public:
	unsigned int win_height = 0, win_width = 0;
	Controller(sf::RenderWindow *_window);
	void draw(); // fetches all objects from the 'Model' file and draws them
	void handleInput(int key, bool value);
};