#include "world.h"

using namespace std;

//возвращает вектор возможных напрвлений движения основного персонажа
//true - если в этом направлении движение возможно
//false - если в эту сторону двигаться нельзы
//стороны перечислены по порядку в enum из common_settings
vector<bool> world::moveability(alives* character)
{
	//некрасиво какт))))0)
	vector<bool> ans;
	for (int i = 0; i < 4; i++)
		ans.push_back(true);

	//пересечение границ мира================================================

	ans = moveability_borders(ans, character);

	//упор в стены=====================================================

	ans = moveability_walls(ans, character);

	//упор в бомбы=====================================================
	
	ans = moveability_bomb(ans, character);

	return ans;
}