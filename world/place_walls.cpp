#include "world.h"

void world::place_walls()
{
	//положение на карте мира
	Vector2i pos_w = { 0,0 };

	for (; pos_w.x < world_size.x; pos_w.x++)
		for (pos_w.y = 0; pos_w.y < world_size.y; pos_w.y++)
		{
			//положение на экране
			Vector2i pos = pos_w;
			pos.x *= place_size_x;
			pos.y *= place_size_y;

			if (pos_w.x % 2 && pos_w.y % 2)
			{
				world_map[pos_w.x][pos_w.y] = new wall(pos, WALL_UNBREAKABLE);
			}
			else
				if ((pos_w.x > 1 || pos_w.y > 1) && rand() % 10 > 3)
				{
					world_map[pos_w.x][pos_w.y] = new wall(pos, WALL_COMMON);
				}
				else
					world_map[pos_w.x][pos_w.y] = new basic_common(pos, FLOOR);
		}
}