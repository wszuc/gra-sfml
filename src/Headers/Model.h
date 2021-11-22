#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Model
{
private:
	// window size
	float window_width, window_height;
	// vectors of sprite, figures, textures etc. that'll be served to draw
	sf::CircleShape shapes_to_draw[1];
	std::vector<sf::Sprite> sprites_to_draw;

	// textures
	sf::Texture background_t;
	// sprites
	sf::Sprite background;

	// load textures from file, invoked in constructior
	void loadTextures();

public:
	sf::CircleShape getCircleShapes();
	sf::Sprite getSprites();
	Model(float width, float height); // initial load of objects into the scene
};