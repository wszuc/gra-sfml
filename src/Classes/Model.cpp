#include "Headers/Model.h"

void Model::init(float width, float height)
{
	// we'll need window size for scaling
	window_width = width;
	window_height = height;

	loadTextures();
}

std::vector<sf::Sprite> Model::getSprites()
{
	return sprites_to_draw;
}

sf::Vector2u Model::getSize(sf::Sprite sprite)
{
	return sprite.getTexture()->getSize();
}

void Model::loopBackground(bool whichone){
	if(whichone==0){
		sprites_to_draw.at(0).move(background_real_size, 0);
	} else{
		sprites_to_draw.at(1).move(background_real_size, 0);
	}
}

void Model::loadTextures()
{
	// background
	background_t.loadFromFile("./content/background.png");
	background_scale = window_height / background_t.getSize().y;
	background.setScale(background_scale, background_scale);
	background.setTexture(background_t);
	sprites_to_draw.insert(sprites_to_draw.begin(), background);
	background_real_size = background_scale*background_t.getSize().x;
	// second backgorund
	background2.setScale(background_scale, background_scale);
	background2.setTexture(background_t);
	background2.setPosition(background_t.getSize().x * background_scale, 0);
	sprites_to_draw.insert(sprites_to_draw.end(), background2);
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
