#pragma once
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Model.h"
#include <SFML/System.hpp>

class Controller
{
private:
	unsigned short state = 0;  // current state of the game; 0 - menu, 1 - game, 2 - pause
	sf::RenderWindow *_window; // pointer to the window
	Model model;
	sf::View view;
	std::vector<sf::Sprite> sprites;
	bool current_background_inidicator = 0;
	bool single_pressed=0;

	sf::Sprite current_background;
	sf::Clock gravityClock;
	sf::Time elapsed;

	const float gravityForce = 5;
	const float initialGravityBoost = 10;
	const float spaceKick = 300; // kick kick kick!!!!!!!!!!!1

public:
	Controller(sf::RenderWindow *_window);
	void draw(); // fetches all objects from the 'Model' file and draws them
	void handleInput(int key, bool value);
};