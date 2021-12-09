#include "../Headers/Renderer.h"
#include "../Headers/Controller.h"

Renderer::Renderer(unsigned int width, unsigned int height)
{
	window.create(sf::VideoMode(width, height), "Flappy Bird Clone", sf::Style::Default);
	std::cout << "Window created, size x: " << window.getSize().x << "Size y: " << window.getSize().y << std::endl;
}

Renderer::~Renderer() {}

void Renderer::run()
{
	sf::RenderWindow *_window;
	window.setFramerateLimit(60);
	_window = &window;
	// Creates controller instance
	Controller controller(_window);
	// Creates main lopp
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Space)
				{
					controller.handleInput(1, 0);
				}
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::Space)
				{
					controller.handleInput(1, 1);
				}
			}
		}
		window.clear(sf::Color::Green);
		controller.draw();
		window.display();
	}
}