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

void Model::moveBird(float value, float x_value)
{
	sprites_to_draw.at(2).move(x_value, value);
}

void Model::loopBackground(bool whichone)
{
	if (whichone == 0)
	{
		sprites_to_draw.at(0).move(background_real_size, 0);
	}
	else
	{
		sprites_to_draw.at(1).move(background_real_size, 0);
	}
}

void Model::reversePipe(unsigned int whichone)
{
	sprites_to_draw.at(whichone + 3).rotate(60);
}

void Model::checkCollisions()
{
	for(auto i=0; i<10; i++){
		if(pipe[i].getGlobalBounds().intersects(sprites_to_draw.at(2).getGlobalBounds())){
		}
	}
}

void Model::placePipe(unsigned int whichone, unsigned int x, unsigned int y, unsigned int height)
{
	sprites_to_draw.at(whichone + 3).setScale(1, (float)height / pipe_t.getSize().y);
	// TODO: obracaj górne rury

	/*if((whichone+3)%2==1){
		sprites_to_draw.at(whichone+3).rotate(180);
		sprites_to_draw.at(whichone+3).move(pipe_t.getSize().x,pipe_t.getSize().y*(float)height/pipe_t.getSize().y);
	}*/

	sprites_to_draw.at(whichone + 3).setPosition(x, y);
}

void Model::loadTextures()
{
	// background
	background_t.loadFromFile("./content/background.png");
	background_scale = window_height / background_t.getSize().y;
	background.setScale(background_scale, background_scale);
	background.setTexture(background_t);
	sprites_to_draw.insert(sprites_to_draw.begin(), background);
	background_real_size = background_scale * background_t.getSize().x;
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
	bird.setOrigin(bird_t.getSize().x / 2, bird_t.getSize().y / 2);
	bird.setPosition(window_width / 2, window_height / 2);
	sprites_to_draw.insert(sprites_to_draw.end(), bird);

	// pipe
	pipe_t.loadFromFile("./content/pipe.png");
	pipe2_t.loadFromFile("./content/pipe2.png");
	for (auto i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			pipe[i].setTexture(pipe2_t);
		}
		else
		{
			pipe[i].setTexture(pipe_t);
		}
		sprites_to_draw.insert(sprites_to_draw.end(), pipe[i]);
	}
}
