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

	// Text for F1 menu
	rules.setFont(arial);
	controlls.setFont(arial);
	rules.setString("Celem gry jest sterowanie ptakiem tak,\nby omijac przeszkody.\nIm dluzej gracz utrzyma sie przy zyciu,\ntym lepszy wynik osiagnie.");
	controlls.setString("\tSPACJA - skok\nF1 - pomoc ESC - menu");
	rules.setOrigin(rules.getLocalBounds().width / 2, rules.getLocalBounds().height / 2);
	controlls.setOrigin(controlls.getLocalBounds().width / 2, controlls.getLocalBounds().height / 2);

	// Text for esc menu

	exit_message.setFont(arial);
	exit_message.setString("Czy na pewno chcesz wyjsc?\n[1] Tak [2] Nie");
	exit_message.setOrigin(exit_message.getLocalBounds().width / 2, exit_message.getLocalBounds().height / 2);

	// Text for main menu

	option[0].setString("[1] Poz. latwy");
	option[1].setString("[2] Poz. sredni");
	option[2].setString("[3] Poz. trudny");
	option[3].setString("[4] Wyjscie");
	for (auto i = 0; i < 4; i++)
	{
		option[i].setFont(arial);
		option[i].setOrigin(option[i].getGlobalBounds().width / 2, option[i].getGlobalBounds().height / 2);
		option[i].setPosition(win_width / 2, 100 + 125 * i);
	}

	// Text for the game over screen

	game_over_message.setFont(arial);
	game_over_message.setString("Przegrales :(\n[1] Wyjscie [2] Wroc do menu glownego");
	game_over_message.setOrigin(game_over_message.getGlobalBounds().width / 2, game_over_message.getGlobalBounds().height / 2);

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

void Controller::setState(short id)
{
	if (state != 3)
	{
		last_state = state;
	}

	state = id;
	if (state == 10)
	{
		state = last_state;
	}
	if (state != 0)
	{
		temp_speed = game_speed;
		temp_delta_s = delta_s;
		game_speed = 0;
		delta_s = 0;
		rules.setPosition(view.getCenter());
		controlls.setPosition(view.getCenter().x, win_height - 100);
		exit_message.setPosition(view.getCenter());
		game_over_message.setPosition(view.getCenter());
	}
	else
	{
		game_speed = temp_speed;
		delta_s = temp_delta_s;
		gravity_clock.restart();
	}
}

void Controller::changeDifficulity(int decrease_gap, int increase_speed)
{
	gap_height -= decrease_gap;
	game_speed += increase_speed;
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

			unsigned int second_height = win_height - randomised_h - gap_height;
			model.placePipe(i + 1, last_dist + gap_width, win_height - second_height, second_height);
			last_dist += gap_width;
		}
	}

	// Calculating gravity induced distance
	if (getState() == 0)
	{
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
	}

	// Adding movement

	view.move(game_speed, 0);
	points.move(game_speed, 0);
	model.moveBird(delta_s, game_speed);
	_window->setView(view);

	// Collisions

	for (auto i = 3; i < 13; i++)
	{
		if (sprites.at(2).getGlobalBounds().intersects(sprites.at(i).getGlobalBounds()))
		{
			setState(4);
		}
	}

	// Setting up and drawing a scene

	switch (state)
	{
	case 0:
		// Drawing all sprites

		for (auto i = sprites.begin(); i != sprites.end(); i++)
		{
			_window->draw(*i);
		}

		// Draw text
		score_str = "Punkty: " + to_string(score);
		points.setString(score_str);
		_window->draw(points);
		break;

	case 1:
		// Drawing main menu
		for (auto i = 0; i < 4; i++)
		{
			_window->draw(option[i]);
		}
		break;
	case 2:
		// Drawing F1 menu
		_window->draw(rules);
		_window->draw(controlls);
		break;
	case 3:
		_window->draw(exit_message);
		break;
	case 4:
		_window->draw(game_over_message);
		break;
	default:
		break;
	}
}