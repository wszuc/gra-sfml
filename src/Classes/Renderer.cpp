#include "../Headers/Renderer.h"
#include "../Headers/Controller.h"

Renderer::Renderer(unsigned int width, unsigned int height)
{
	window.create(sf::VideoMode(width, height), "SFML game", sf::Style::Default);
}

Renderer::~Renderer()
{
	std::cout << "Destructor hahah" << std::endl;
}
void Renderer::run(Controller *_controller)
{
	// Creates pointer to the window that's used by the controller
	sf::RenderWindow *_window = &window;
	// Creates main lopp
	while (window.isOpen())
	{
		while (!window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Green);
		_controller->draw(_window);
		window.display();
	}
}