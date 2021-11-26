#pragma once
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Model.h"

class Controller
{
private:
	unsigned short state = 0; // current state of the game; 0 - menu, 1 - game, 2 - pause
	sf::RenderWindow *_window; // pointer to the window
	Model model;
	sf::View view;
	std::vector<sf::Sprite> sprites;
	bool current_background_inidicator = 0;
	sf::Sprite current_background;
public:
	Controller(sf::RenderWindow *_window);
	void draw(); // fetches all objects from the 'Model' file and draws them
};