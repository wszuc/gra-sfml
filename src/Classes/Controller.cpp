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
	gravityClock.restart();
	std::cout << "Controller constructed";
}

void Controller::handleInput(int key, bool value)
{
	switch (key)
	{
	case 1: // space
		if (value == 0 && single_pressed == 0)
		{
			std::cout << "space pressed" << std::endl;
			// reset current gravity effects and add temporary reverse gravity
			gravityClock.restart();
			model.moveBird(-spaceKick, 0);
			single_pressed = 1;
		}
		if (value == 1)
		{
			single_pressed = 0;
		}
		break;

	default:
		break;
	}
}

void Controller::draw() // its injected into the main loop
{
	// Setting some things -> copying sprites to draw
	sprites = model.getSprites();
	// Handling input

	// Gravity

	elapsed = gravityClock.getElapsedTime();
	model.moveBird(gravityForce * elapsed.asSeconds() * elapsed.asSeconds() + initialGravityBoost, 0);

	// Looping background

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

	// Drawing all sprites

	view.move(5, 0);
	model.moveBird(0, 5);
	_window->setView(view);
	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}
}