#include "./Headers/Controller.h"

Controller::Controller(sf::RenderWindow *_window)
{
	this->_window = _window;
	model.init(_window->getSize().x, _window->getSize().y);
	_window->setView(model.getView());
}

void Controller::draw()
{
	// looping through vector with sprites and drawin them in order
	sprites = model.getSprites();
	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}
}