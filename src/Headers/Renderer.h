#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include <string>

class Renderer
{
private:
	sf::RenderWindow window;
	sf::Event e;
	bool once_opened = 0;
public:
	Renderer(unsigned int width, unsigned int height);
	~Renderer();
	void run();
	void save(string data);
	string open();
};
