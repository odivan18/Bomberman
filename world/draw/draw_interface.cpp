#include "world.h"

void world::draw_interface()
{

	for (int i = 0; i < interf.size(); i++)
	{
		window_main.draw(interf[i].get_sprite());
	}

	interf[2].set_texture(num_textures_names[main_character.get_lives()]);
}