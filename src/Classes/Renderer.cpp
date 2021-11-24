#include "../Headers/Renderer.h"
#include "../Headers/Controller.h"

Renderer::Renderer(unsigned int width, unsigned int height)
{
	window.create(sf::VideoMode(width, height), "Flappy Bird Clone", sf::Style::Default);
}

Renderer::~Renderer()
{
	std::cout << "Window destructed" << std::endl;
}
void Renderer::run()
{
	// Creates controller instance
	Controller controller(&window);
	// Creates main lopp
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Green);
		controller.draw();
		window.display();
	}
}