#include<iostream>
#include "Fish.h"

using namespace std;
size_t Fish::s_lake[10][10] = {0};
size_t Fish::s_numberOfLiving = 0;
int main() {
	srand((unsigned int)time(0));
	Fish A({2, 1});
	A.print();
	return 0;
} 