#include "Headers/Model.h"

void Model::init(float width, float height)
{
	// we'll need window size for scaling
	window_width = width;
	window_height = height;

	loadTextures();

	view.setSize(sf::Vector2f(window_width, window_height));
	view.setCenter(sf::Vector2f(window_width / 2, window_height / 2));
	std::cout << "View set" << std::endl;
}

sf::View Model::getView()
{
	return view;
}

std::vector<sf::Sprite> Model::getSprites()
{
	return sprites_to_draw;
}

void Model::loadTextures()
{
	// background
	background_t.loadFromFile("./content/background.png");
	background_t.setRepeated(true);
	background_scale = window_height / background_t.getSize().y;
	background.setScale(background_scale, background_scale);
	background.setTexture(background_t);
	sprites_to_draw.insert(sprites_to_draw.begin(), background);

	// bird
	bird_t.loadFromFile("./content/bird.png");
	bird_scale = 2;
	bird.setScale(bird_scale, bird_scale);
	bird.setTexture(bird_t);
	sprites_to_draw.insert(sprites_to_draw.end(), bird);

	// pipe
	pipe_t.loadFromFile("./content/pipe.png");
	pipe_scale = 1;
	pipe.setScale(pipe_scale, pipe_scale);
	pipe.setTexture(pipe_t);
	sprites_to_draw.insert(sprites_to_draw.end(), pipe);
}
