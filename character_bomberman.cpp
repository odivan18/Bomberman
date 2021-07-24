#include "character_bomber.h"

bomber::bomber()
{

}

void bomber::move(float elapsed_time)
{
	//перемещение, если нажата только одна кнопке
	if (is_only_one_true(move_dirs))
	{
		if (move_dirs[RIGHT])
		{
			position.x += move_speed * elapsed_time;			
		}

		if (move_dirs[LEFT])
		{
			position.x -= move_speed * elapsed_time;			
		}

		if (move_dirs[UP])
		{
			position.y -= move_speed * elapsed_time;			
		}

		if (move_dirs[DOWN])
		{
			position.y += move_speed * elapsed_time;			
		}
	}

	stop_moveing();

	go_on_rails();

	//перемещаем спрайт
	sprite.setPosition(position.x, position.y);

	set_log_pos();
}

int bomber::update(float elapsed_time)
{
	if (invul_time_left > 0)
	{
		invul_time_left -= elapsed_time;

		blinking();
	}

	move(elapsed_time);

	for (int i = 0; i < planted_bombs.size(); i++)
		planted_bombs[i].update(elapsed_time);

	if (lives <= 0)
	{
		
	}

	return 1;
}

void bomber::delete_bomb(int bomb_n)
{
	if (bomb_n < planted_bombs.size())
	{
		planted_bombs.erase(planted_bombs.begin() + bomb_n);
	}
}

bomber bomber::operator=(bomber* orig)
{
	//тупа копируем все подряд
	move_speed = orig->get_move_speed();
	can_pass_walls = orig->get_passability();
	lives = orig->get_hp();
	hand_damage = orig->get_hand_damage();
	texture_adress = orig->get_tex_adress();
	position = orig->get_position();
	boom_size = orig->get_boom_size();
	bomb_damage = orig->get_bomb_damage();
	bomb_timer = orig->get_timer();
	max_bombs_planted = orig->get_max_bombs_possible();
	for (int i = 0; i < 4; i++)
		move_dirs.push_back(orig->get_move_dir(i));

	texture.loadFromFile(texture_adress);
	sprite.setTexture(texture);

	obj_type = BOMBERMAN;

	return *this;
}