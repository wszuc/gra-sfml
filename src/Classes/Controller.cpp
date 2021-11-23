#include "./Headers/Controller.h"

void Controller::draw(sf::RenderWindow *_window)
{
	Model model(_window->getSize().x, _window->getSize().y);

	_window->setView(model.getView());

	// looping through vector with sprites and drawin them in order
	sprites = model.getSprites();
	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}
}