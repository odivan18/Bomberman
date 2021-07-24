#include "common_settings.h"

//basic_common::basic_common()
//{
//	Vector2i pos;
//	pos.x = 0;
//	pos.y = 0;
//	//установка объекта на позицию
//	position = pos;
//	//дарование текстуры
//	texture.loadFromFile(bomb_texture);
//}

basic_common::basic_common( Vector2i pos, obj_types type)
{
	//установка объекта на позицию
	position = pos;
	set_log_pos();


	//дарование текстуры
	set_texture(textures_names[type]);
	sprite.setPosition(pos.x, pos.y);
	

	obj_type = type;
	lives = hp_default[type];
}

basic_common::basic_common(Vector2i pos, std::string tex_adr)
{
	position = pos;
	set_log_pos();


	//дарование текстуры
	set_texture(tex_adr);
	sprite.setPosition(pos.x, pos.y);
}

basic_common::basic_common(const basic_common& ob)
{
	position = ob.position;
	set_log_pos();

	set_texture(ob.texture_adress);
	sprite.setPosition(position.x, position.y);

	lives = ob.lives;
	obj_type = ob.obj_type;
}

Vector2i basic_common::get_position()
{
	return position;
}

Vector2i basic_common::get_log_pos()
{
	return logic_pos;
}

Sprite basic_common::get_sprite()
{
	return sprite;
}

std::string basic_common::get_tex_adress()
{
	return texture_adress;
}

obj_types basic_common::get_obj_type()
{
	return obj_type;
}

int basic_common::get_lives()
{
	return lives;
}

void basic_common::set_texture(std::string adress)
{
	texture_adress = adress;
	texture.loadFromFile(adress);
	sprite.setTexture(texture);
}

void basic_common::set_log_pos()
{
	logic_pos.x = position.x / place_size_x;
	logic_pos.y = position.y / place_size_y;

	if (position.x % place_size_x > place_size_x / 2)
		logic_pos.x++;
	if (position.y % place_size_y > place_size_y / 2)
		logic_pos.y++;
}

void basic_common::set_position(sf::Vector2i pos)
{
	position = pos;
	sprite.setPosition(pos.x, pos.y);
}

void basic_common::hit(int damage)
{
	lives -= damage;
}