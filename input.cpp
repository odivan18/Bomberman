#include "world.h"

void world::input()
{
	std::vector<bool> can_he_move = moveability(&main_character);

	main_character.stop_down();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window_main.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (main_character.get_position().y % place_size_y == 0)
		{
			can_he_move[LEFT] ? main_character.move_left() : main_character.stop_left();
		}
		else
		{
			if (main_character.get_position().y % place_size_y < place_size_y / 2)
			{
				can_he_move[UP] ? main_character.move_up() : main_character.stop_up();
			}
			else
			{
				can_he_move[DOWN] ? main_character.move_down() : main_character.stop_down();
			}
		}

	}


	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (main_character.get_position().y % place_size_y == 0)
		{
			can_he_move[RIGHT] ? main_character.move_right() : main_character.stop_right();
		}
		else
		{
			if (main_character.get_position().y % place_size_y < place_size_y / 2)
			{
				can_he_move[UP] ? main_character.move_up() : main_character.stop_up();
			}
			else
			{
				can_he_move[DOWN] ? main_character.move_down() : main_character.stop_down();
			}
		}
	}


	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (main_character.get_position().x % place_size_x == 0)
		{
			can_he_move[UP] ? main_character.move_up() : main_character.stop_up();
		}
		else
		{
			if (main_character.get_position().x % place_size_x < place_size_x / 2)
			{
				can_he_move[LEFT] ? main_character.move_left() : main_character.stop_left();
			}
			else
			{
				can_he_move[RIGHT] ? main_character.move_right() : main_character.stop_right();
			}
		}
	}


	if (Keyboard::isKeyPressed(Keyboard::S))
	{

		if (main_character.get_position().x % place_size_x == 0)
		{
			can_he_move[DOWN] ? main_character.move_down() : main_character.stop_down();
		}
		else
		{
			if (main_character.get_position().x % place_size_x < place_size_x / 2)
			{
				can_he_move[LEFT] ? main_character.move_left() : main_character.stop_left();
			}
			else
			{
				can_he_move[RIGHT] ? main_character.move_right() : main_character.stop_right();
			}
		}
	}


	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (main_character.get_planted_bombs().size() < main_character.get_max_bombs_possible())

			main_character.plant_bomb();
	}
}