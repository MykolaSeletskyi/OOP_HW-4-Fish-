#pragma once
#include <iostream>
#include<Windows.h>
#include<time.h>
const HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
class Fish
{
	COORD m_coord;
	size_t m_live;
public:
	static size_t s_lake[10][10];
	static size_t s_numberOfLiving;
	Fish(COORD coord = randCoord(), size_t live = 100)
		:m_coord(coord.X<0||coord.Y<0? randCoord():coord)//якщо координати менші за 0 то рандомить коректні
		,m_live(live) {};
	static COORD randCoord() {
		bool temp = true;
		COORD result;
		do
		{
			result.X = rand() % 10;
			result.Y = rand() % 10;
			if (s_lake[result.X][result.Y] == 0)
			{
				s_lake[result.X][result.Y] = 1;
				temp = false;
			}
		} while (temp);
		return result;
	}
	void print() {
		SetConsoleCursorPosition(hStdOut, m_coord);
		std::cout << "@";
	}
	void hide()
	{
		SetConsoleCursorPosition(hStdOut, m_coord);
		std::cout << " ";
	}
};

