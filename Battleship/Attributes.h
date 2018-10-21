#pragma once
#include <vector>

class Attributes
{

protected:
	struct location //use to grab location of each ship so we can hide the enemies ships
	{
		location(int xCoor, int yCoor)
			:x(xCoor), y(yCoor){}

		int x;
		int y;
	};
	std::vector<location> locations;

	static constexpr int boardX = 10, boardY = 10;
	unsigned int shipCount = 0;
	char ship = 'S';
	const char hit = 'X';
	const char miss = 'O';
	char board[boardX][boardY];
};