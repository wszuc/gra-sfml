#include <SFML/Graphics.hpp>
#include "./Headers/Renderer.h"
#include "./Headers/Controller.h"

int main()
{
	Renderer game(700, 800); // window size
	for (;;)
	{
		game.run();
	}
	return 0;
}