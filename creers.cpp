#include "creeps.h"


void creeps::move(float elapsed_time)
{
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

	go_on_rails();

	//перемещаем спрайт
	sprite.setPosition(position.x, position.y);

	set_log_pos();
}

int creeps::update(float elapsed_time)
{
	move(elapsed_time);

	return 1;
}

creeps creeps::operator=(creeps orig)
{
	position = orig.position;
	logic_pos = orig.logic_pos;

	set_texture(orig.texture_adress);
	sprite.setPosition(position.x, position.y);

	obj_type = orig.obj_type;

	move_speed = orig.move_speed;
	can_pass_walls = orig.can_pass_walls;
	hand_damage = orig.hand_damage;
	move_dirs = orig.move_dirs;

	lives = orig.lives;

	return *this;
}