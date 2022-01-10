#include "./Headers/Controller.h"

Controller::Controller(sf::RenderWindow *_window)
{
	this->_window = _window;
	win_height = _window->getSize().y;
	win_width = _window->getSize().x;
	max_height = 0.6 * win_height;
	model.init(win_width, win_height);
	view.setSize(win_width, win_height);
	view.setCenter(sf::Vector2f(win_width / 2, win_height / 2));
	_window->setView(view);
	current_background_inidicator = 0;
	gravity_clock.restart();

	arial.loadFromFile("./content/arial.ttf");
	points.setFont(arial);

	gap_height = 0.4 * win_height;
	gap_width = 0.5 * win_width;

	// Placing first 10 pipes
	int j = 0;
	for (auto i = 0; i < gap_width * 5; i += gap_width)
	{
		unsigned int randomised_h = randomiser.random(min_height, static_cast<int>(max_height));
		model.placePipe(j, starting_dist + i, 0, randomised_h);
		// model.reversePipe(j);
		unsigned int second_height = win_height - randomised_h - gap_height;
		model.placePipe(j + 1, starting_dist + i, win_height - second_height, second_height);
		j += 2;
	}
	last_dist = 5 * gap_width;
}

void Controller::handleInput(int key, bool value)
{
	switch (key)
	{
	case 1: // space
		if (value == 0 && single_pressed == 0)
		{
			// reset current gravity effects and add temporary reverse gravity
			gravity_clock.restart();
			single_pressed = 1;
			is_upward = 1;
			delta_s = -space_kick;
			score++;
		}
		if (value == 1)
		{
			single_pressed = 0;
		}
		break;

	default:
		break;
	}
}

void Controller::draw() // its injected into the main loop
{
	// Setting some things -> copying sprites to draw

	sprites = model.getSprites();

	// Looping background

	if (current_background_inidicator == 0)
	{
		if (view.getCenter().x - view.getSize().x / 2 >= sprites.at(0).getPosition().x + model.background_real_size)
		{
			current_background_inidicator = 1;
			model.loopBackground(0);
		}
	}
	if (current_background_inidicator == 1)
	{
		if (view.getCenter().x + view.getSize().x / 2 >= sprites.at(1).getPosition().x + model.background_real_size)
		{
			current_background_inidicator = 0;
			model.loopBackground(1);
		}
	}

	// Looping pipes -> deleting ones that are left behind, generating new in their place
	for (auto i = 0; i < 9; i += 2)
	{
		if (view.getCenter().x - view.getSize().x > sprites.at(i + 3).getPosition().x)
		{
			unsigned int randomised_h = randomiser.random(min_height, static_cast<int>(max_height));
			model.placePipe(i, last_dist + gap_width, 0, randomised_h);
			// model.reversePipe(i);
			unsigned int second_height = win_height - randomised_h - gap_height;
			model.placePipe(i + 1, last_dist + gap_width, win_height - second_height, second_height);
			last_dist += gap_width;
		}
	}

	// Calculating gravity induced distance

	if (is_upward == 0)
	{
		delta_s = initial_gravity_boost + gravity_force * gravity_clock.getElapsedTime().asSeconds() * gravity_clock.getElapsedTime().asSeconds() / 2;
	}
	else
	{
		if (delta_s < 1)
		{
			delta_s += gravity_force * gravity_clock.getElapsedTime().asSeconds() * gravity_clock.getElapsedTime().asSeconds() / 2;
		}
		else
		{
			is_upward = 0;
		}
	}

	// Adding movement

	view.move(5, 0);
	points.move(5, 0);
	model.moveBird(delta_s, 5);
	_window->setView(view);

	// Drawing all sprites

	for (auto i = sprites.begin(); i != sprites.end(); i++)
	{
		_window->draw(*i);
	}

	// Draw text

	points.setString(); // polacz string punkty z wynikiem
	_window->draw(points);
}