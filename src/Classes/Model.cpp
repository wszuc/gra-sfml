#include "Headers/Model.h"

Model::Model(float width, float height)
{
	window_width = width;
	window_height = height;
	// we'll need window size for scaling
	shapes_to_draw[0] = sf::CircleShape(20);
	loadTextures();
}

sf::CircleShape Model::getCircleShapes()
{
	return shapes_to_draw[0];
}

sf::Sprite Model::getSprites()
{
	return sprites_to_draw[0];
}

void Model::loadTextures()
{
	background_t.loadFromFile("./content/background.png");
	background_t.setRepeated(true);
	background.setTexture(background_t);
	// setting properties and scaling the background
	float scale = window_height / background_t.getSize().y;
	background.setScale(scale, scale);
	sprites_to_draw.insert(sprites_to_draw.begin(), background);
}
