#pragma once
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Model.h"

class Controller
{
private:
	unsigned short state = 0; // current state of the game; 0 - menu, 1 - game, 2 - pause
	std::vector<sf::Sprite> sprites;

public:
	void draw(sf::RenderWindow *_window); // fetches all objects from the 'Model' file and draws them
};