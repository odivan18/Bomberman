#include "bomba.h"

int bomb::update(float elapsed_time)
{
	timer -= elapsed_time;

	if (timer > 2.9)
		set_texture(textures_names[BOMB]);

	if (timer <= 0)
	{
		return 0;
	}
}


bomb bomb::operator=(bomb* orig)
{
	position = orig->get_position();
	logic_pos = orig->get_log_pos();

	texture_adress = orig->get_tex_adress();
	texture.loadFromFile(texture_adress);
	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);

	obj_type = orig->get_obj_type();
	
	timer = orig->get_timer();
	power = orig->get_power();
	damage = orig->get_damage();

	return *this;
}