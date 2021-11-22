#include <SFML/Graphics.hpp>
#include "./Headers/Renderer.h"
#include "./Headers/Controller.h"

int main()
{
	Renderer game(700, 800);
	Controller controller;
	Controller *_controller = &controller;
	game.run(_controller);
	return 0;
}