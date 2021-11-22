#include "./Headers/Controller.h"

void Controller::draw(sf::RenderWindow *_window)
{
	// drawing objects from model in order
	Model model;
	// drawing circle shapes
	//_window->draw(model.getCircleShapes());
	_window->draw(model.getSprites());
}