#pragma once
#include "Fish.h"

COORD Fish::randCoord()
{
	bool temp = true;
	COORD result;
	do
	{
		result.X = rand() % SIZE_LAKE;
		result.Y = rand() % SIZE_LAKE;
		if (s_lake[result.X][result.Y] == 0)
		{
			temp = false;
		}
	} while (temp);
	return result;
}

void Fish::addSeaweed(size_t number)
{
	COORD temp;
	for (size_t i = 0; i < number; i++)
	{
		temp = randCoord();
		SetConsoleCursorPosition(handle, temp);
		std::cout << "~";
		s_lake[temp.X][temp.Y] = 2;
	}
}

COORD Fish::randStep() const
{
	bool temp = true;
	COORD result;
	s_lake[m_coord.X][m_coord.Y] = 0;
	do
	{
		result = m_coord;
		result.X += rand() % 3 - 1;
		result.Y += rand() % 3 - 1;
		if (result.X >= 0 && result.X < SIZE_LAKE && result.Y >= 0 && result.Y < SIZE_LAKE)
		{
			if (s_lake[result.X][result.Y] != 1)
			{
				temp = false;
			}
		}
	} while (temp);
	return result;
}

void Fish::print()
{
	if (m_live != 0)
	{
		SetConsoleCursorPosition(handle, m_coord);
		std::cout << "@";
		displayed = true;
	}
}

void Fish::hide()
{
	SetConsoleCursorPosition(handle, m_coord);
	std::cout << " ";
	displayed = false;
}

void Fish::to_move()
{
	if (m_live != 0)
	{
		COORD coord = randStep();
		if (displayed)
		{
			hide();
		}
		if (s_lake[coord.X][coord.Y] == 0)
		{
			m_coord = coord;
			if ((--m_live) == 0)
			{
				s_lake[m_coord.X][m_coord.Y] = 0;
				--s_numberOfLiving;
				return;
			}
		}
		else if (s_lake[coord.X][coord.Y] == 2)
		{
			m_coord = coord;
			m_live += 10;
		}
		s_lake[m_coord.X][m_coord.Y] = 1;
		print();
	}
}
