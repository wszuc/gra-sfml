#include "Headers/Model.h"

Model::Model()
{
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
	background.setTexture(background_t);
	sprites_to_draw.insert(sprites_to_draw.begin(), background);
}
