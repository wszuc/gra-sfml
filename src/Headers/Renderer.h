#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Controller.h"

class Renderer
{
private:
	sf::RenderWindow window;
	sf::Event e;

public:
	Renderer(unsigned int width, unsigned int height);
	~Renderer();
	void run();
	
};
