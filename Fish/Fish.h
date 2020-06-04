#pragma once
#include <iostream>
#include<Windows.h>
#include<time.h>
const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
const size_t SIZE_LAKE = 30;
class Fish
{
	COORD m_coord;
	size_t m_live;
	bool displayed = false;
	static size_t s_numberOfLiving;
	static char s_lake[SIZE_LAKE][SIZE_LAKE];//0-пусто , 1-риба , 2-водорості
public:

	Fish(COORD coord = randCoord(), size_t live = 100)
		:m_coord(coord.X < 0 || coord.Y < 0 ? randCoord() : coord)//якщо координати менші за 0 то рандомить коректні
		, m_live(live)
	{
		s_numberOfLiving++;
		s_lake[m_coord.X][m_coord.Y] = 1;
	};

	static size_t&  getNumberOfLiving() {
		return s_numberOfLiving;
	}
	static COORD randCoord();
	static void addSeaweed(size_t number);

	COORD randStep()const;

	void print();
	void hide();
	void to_move();
};

