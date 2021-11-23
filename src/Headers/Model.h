#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Model
{
private:
	// window size
	float window_width, window_height;
	// camera
	sf::View view;
	// vectors of sprite, figures, textures etc. that'll be served to draw
	std::vector<sf::Sprite> sprites_to_draw;

	// textures
	sf::Texture background_t, bird_t, pipe_t;
	// textures' scales
	float background_scale, bird_scale, pipe_scale;
	// sprites
	sf::Sprite background, bird, pipe;
	// increasing speed factor
	float speed_factor = 1;

	// load textures from file, invoked in constructior
	void loadTextures();

	void setView();

public:
	std::vector<sf::Sprite> getSprites();
	sf::View getView();
	Model(float width, float height); // initial load of objects into the scene
};