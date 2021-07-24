#include "ghost_creep.h"

void ghost_creep::move(float elapsed_time)
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

int ghost_creep::update(float elapsed_time)
{
	move(elapsed_time);

	return 1;
}

ghost_creep ghost_creep::operator=(ghost_creep* orig)
{
	set_texture(orig->get_tex_adress());

	position = orig->get_position();
	logic_pos = orig->get_log_pos();

	obj_type = GHOST;
	lives = orig->get_lives();

	move_speed = orig->get_move_speed();
	can_pass_walls = orig->get_passability();
	hand_damage = orig->get_hand_damage();

	invul_time_left = orig->get_invul_time_left();

	return *this;
}