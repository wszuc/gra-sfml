#include "./Headers/Controller.h"

void Controller::draw(sf::RenderWindow *_window)
{
	Model model(_window->getSize().x, _window->getSize().y);

	// looping through vector with sprites and drawin them in order
	// pointer for fast access
	sprites = model.getSprites();
	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}
}