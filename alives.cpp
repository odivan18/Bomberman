#include "alives.h"

alives::alives()
{

}

//alives::alives(float ms, bool wall_pass, int hp, int damage, std::string tex_adress, sf::Vector2i pos)
//{
//	//заполнение набора активных направлений движения
//	for (int i = 0; i < 4; i++)
//		move_dirs.push_back(false);
//
//	move_speed = ms;
//	can_pass_walls = wall_pass;
//	lives = hp;
//	hit_damage = damage;
//}

//устанавливает персонажа на "рельсы", если до них оталось 3 и меньше пикселей
void alives::go_on_rails()
{
	int rails_rad = move_speed / 60/1.2;

	if (position.x % place_size_x <= rails_rad || position.x % place_size_x >= place_size_x - rails_rad)
		position.x = logic_pos.x * place_size_x;

	if (position.y % place_size_y <= rails_rad || position.y % place_size_y >= place_size_y - rails_rad)
		position.y = logic_pos.y * place_size_y;
}

void alives::hit(int damage)
{
	if (invul_time_left <= 0)
	{
		lives -= damage;
		invul_time_left = 1;
	}
}

void alives::move_right()
{
	move_dirs[RIGHT] = true;
}
void alives::move_left()
{
	move_dirs[LEFT] = true;
}
void alives::move_up()
{
	move_dirs[UP] = true;
}
void alives::move_down()
{
	move_dirs[DOWN] = true;
}

void alives::stop_left()
{
	move_dirs[LEFT] = false;
}
void alives::stop_right()
{
	move_dirs[RIGHT] = false;
}
void alives::stop_up()
{
	move_dirs[UP] = false;
}
void alives::stop_down()
{
	move_dirs[DOWN] = false;
}
void alives::stop_moveing()
{
	stop_right();
	stop_left();
	stop_up();
	stop_down();
}

bool alives::is_on_rails()
{
	if (position.x % place_size_x == 0)
		if (position.y % place_size_y == 0)
			return true;
	return false;
}

float alives::get_move_speed() 
{ 
	return move_speed;
}
bool alives::get_passability() 
{ 
	return can_pass_walls;
}
int alives::get_hp() 
{ 
	return lives;
}
int alives::get_hand_damage() 
{ 
	return hand_damage;
}
bool alives::get_move_dir(int dir)
{
	return move_dirs[dir];
}
std::vector<bool> alives::get_move_dir()
{
	return move_dirs;
}
float alives::get_invul_time_left()
{
	return invul_time_left;
}

void alives::blinking()
{
	int inv_tl = invul_time_left * 10;

	if (inv_tl % 2 == 1)
	{
		texture.loadFromFile("textures\\blank_texture.png");		
	}
	else
	{
		texture.loadFromFile(textures_names[obj_type]);
	}

	sprite.setTexture(texture);
}