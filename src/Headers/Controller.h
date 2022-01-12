#pragma once
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Model.h"
#include "Randomiser.h"

class Controller
{
private:
	short state = 1;  // current state of the game; 0 - game, 1 - menu, 2 - F1, 3 - escape, 4 - game over
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

short last_state=9;
	int game_speed = 5, temp_speed, temp_delta_s;
	const float gravity_force = 200;
	const float initial_gravity_boost = 5;
	const float space_kick = 15;
	float delta_s = 0, upward_force = 0;

	Randomiser randomiser;
	unsigned int starting_dist = 500, max_height, min_height = 50;
	float gap_height, gap_width, last_dist;

	sf::Font arial;
	sf::Text points;
	sf::Clock points_clock;
	int score=0;
	string score_str;

	sf::Text rules, controlls;
	sf::Text option[4];
	sf::Text exit_message;
	sf::Text game_over_message;

public:
	unsigned int win_height = 0, win_width = 0;
	Controller(sf::RenderWindow *_window);
	void draw(); // fetches all objects from the 'Model' file and draws them
	void handleInput(int key, bool value);
	void setState(short id);
	short getState(){return state;};
	void changeDifficulity(int decrease_gap, int increase_speed);
};