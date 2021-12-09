#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>


class Model
{
private:
	// window size
	float window_width, window_height;
	// factor of speed increase
	const float speed = 5;
	// vectors of sprite, figures, textures etc. that'll be served to draw
	std::vector<sf::Sprite> sprites_to_draw;

	// textures
	sf::Texture background_t, bird_t, pipe_t;
	// textures' scales
	float background_scale, bird_scale, pipe_scale;
	// sprites
	sf::Sprite background, background2, bird, pipe;

	// load textures from file, invoked in constructior
	void loadTextures();

public:

	float background_real_size;
	std::vector<sf::Sprite> getSprites();
	sf::Vector2u getSize(sf::Sprite sprite);
	void init(float width, float height);
	void loopBackground(bool whichone);
	void moveBird(float value, float x_value);
};