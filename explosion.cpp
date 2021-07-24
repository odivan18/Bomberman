#include "explosion.h"


int explosion::update(float elapsed_time)
{
	if (lifetime < 2. / 3)
	{
		if(texture_adress!= "textures\\explosion_texture_2.png")
		set_texture("textures\\explosion_texture_2.png");
	}

	if (lifetime < 1. / 3)
	{
		if (texture_adress != "textures\\explosion_texture_3.png")
		set_texture("textures\\explosion_texture_3.png");
	}

	return lifetime -= elapsed_time;
}

int explosion::get_power()
{
	return power;
}
int explosion::get_damage()
{
	return damage;
}
float explosion::get_time_left()
{
	return lifetime;
}

explosion explosion::operator=(explosion orig)
{
	position = orig.get_position();
	logic_pos = orig.get_log_pos();

	set_texture(orig.get_tex_adress());
	sprite.setPosition(position.x, position.y);

	obj_type = EXPLOSION;
	
	damage = orig.get_damage();
	lifetime = orig.get_time_left();

	return *this;
}