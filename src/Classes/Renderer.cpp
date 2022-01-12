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
	controller.setState(1);
	// Creates main lopp
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (e.type == sf::Event::KeyPressed and controller.getState() == 1)
			{
				if (e.key.code == sf::Keyboard::Num1)
				{
					controller.setState(0);
				}
				else if (e.key.code == sf::Keyboard::Num2)
				{
					controller.setState(0);
					controller.changeDifficulity(60, 0);
				}
				else if (e.key.code == sf::Keyboard::Num3)
				{
					controller.setState(0);
					controller.changeDifficulity(60, 1);
				}
				else if (e.key.code == sf::Keyboard::Num4)
				{
					exit(0);
				}
			}
			if (controller.getState() == 3 and e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Num1)
				{
					exit(0);
				}
				if (e.key.code == sf::Keyboard::Num2)
				{
					controller.setState(10);
				}
			}
			if (e.type == sf::Event::KeyPressed and controller.getState() == 2)
			{
				if (e.key.code == sf::Keyboard::F1)
				{
					controller.setState(0);
				}
			}
			if (e.type == sf::Event::KeyPressed and controller.getState() == 0)
			{
				if (e.key.code == sf::Keyboard::Space and controller.getState() == 0)
				{
					controller.handleInput(1, 0);
				}
				if (e.key.code == sf::Keyboard::F1)
				{
					if (controller.getState() == 0)
					{
						controller.setState(2);
					}
					else if (controller.getState() == 2)
					{
						controller.setState(0);
					}
				}
				if (e.key.code == sf::Keyboard::Escape)
				{
					controller.setState(3);
				}
			}
			if (e.type == sf::Event::KeyReleased and controller.getState() == 0)
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