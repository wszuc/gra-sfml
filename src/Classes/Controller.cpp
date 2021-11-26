#include "./Headers/Controller.h"

Controller::Controller(sf::RenderWindow *_window)
{
	this->_window = _window;
	model.init(_window->getSize().x, _window->getSize().y);
	view.setSize(_window->getSize().x, _window->getSize().y);
	view.setCenter(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 2));
	std::cout << "View set, size x: " << view.getSize().x << "Size y: " << view.getSize().y << std::endl;
	std::cout << "Backgorund real size: " << model.background_real_size << std::endl;
	std::cout << "View center x: " << view.getCenter().x << " y: " << view.getCenter().y << std::endl;
	_window->setView(view);
	current_background_inidicator = 0;
}

void Controller::draw() // its injected into the main loop
{
	sprites = model.getSprites();

	// looping background

	std::cout << "View center: " << view.getCenter().x << std::endl;
	if (current_background_inidicator == 0)
	{
		if (view.getCenter().x - view.getSize().x / 2 >= sprites.at(0).getPosition().x + model.background_real_size)
		{
			current_background_inidicator = 1;
			model.loopBackground(0);
		}
	}
	if (current_background_inidicator == 1)
	{
		if (view.getCenter().x + view.getSize().x / 2 >= sprites.at(1).getPosition().x + model.background_real_size)
		{
			current_background_inidicator = 0;
			model.loopBackground(1);
		}
	}
	// looping through vector with sprites and drawin them in order

	view.move(5, 0);
	_window->setView(view);
	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}
}