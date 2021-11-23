#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Model
{
private:
	// window size
	float window_width, window_height;
	// vectors of sprite, figures, textures etc. that'll be served to draw
	std::vector<sf::Sprite> sprites_to_draw;

	// textures
	sf::Texture background_t, bird_t, pipe_t;
	// textures' scales
	float background_scale, bird_scale, pipe_scale;
	// sprites
	sf::Sprite background, bird, pipe;

	// load textures from file, invoked in constructior
	void loadTextures();

public:
	std::vector<sf::Sprite> getSprites();
	Model(float width, float height); // initial load of objects into the scene
};