#pragma once
#include "alives.h"
#include "bomb_planter.h"


//Основной класс игрового персонажа
//Управление с клавиатуры
//
//Устанавливает бомбы в свободные от статичных объектов клетки
//т.е. везде, где сам ходит
// 
//Передвигается как по рельсам
//В туннеле нельзя переместиться чуть в сторону от основного направления
//Если достаточно близко от поворота есть команда в него завернуть,
//продолжаем движение в направлении поворота пока не дойдем до "рельс" нового направления
class bomber:virtual public alives,virtual public bomb_planter, virtual public basic_common
{
protected:
	

public:
	bomber();

	bomber(sf::Vector2i pos) :alives(BOMBERMAN, pos),
		bomb_planter( BOMBERMAN, pos),
		basic_common( pos,BOMBERMAN){}
	//bomber(const bomber& ob);

	//Передвигается как по рельсам
	//В туннеле нельзя переместиться чуть в сторону от основного направления
	//Если достаточно близко от поворота есть команда в него завернуть,
	//продолжаем движение в направлении поворота пока не дойдем до "рельс" нового направления
	void move(float etlapsed_time);
	int update(float elapsed_time);

	void delete_bomb(int bomb_n);

	bomber operator=(bomber* orig);
};