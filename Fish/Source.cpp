#include<iostream>
#include<fstream>
#include "Fish.h"
using namespace std;
char Fish::s_lake[SIZE_LAKE][SIZE_LAKE] = { 0 };
size_t Fish::s_numberOfLiving = 0;
int main() {

	const int countFish = 10;
	Fish A[countFish];
	for (size_t i = 0; i < countFish; i++)
	{
		A[i].print();
	}
	while (true)
	{
		Fish::addSeaweed(rand() % 3);
		for (size_t i = 0; i < countFish; i++)
		{
			A[i].to_move();
		}		
			Sleep(100);       
			SetConsoleCursorPosition(handle, { 30,30 });

			std::cout << "number of living = ";
			std::cout << Fish::getNumberOfLiving();
			std::cout << "   ";
	}

	//Fish B;
	//B.print();
	//while (true)
	//{
	//	B.to_move();
	//	Sleep(100);
	//	Fish::addSeaweed(1);//1 кількість водоростей
	//}

	return 0;
} 