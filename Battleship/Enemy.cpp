#include "Enemy.h"
#include <iostream>
#include "Utils.h"
#include "Player.h"
#include <Windows.h>
#include <assert.h>

Enemy::Enemy()
{
	initBoard();

	for(int i=0; i<6; ++i)
		initShips();

	grabShipLocations();

	//initBoard();
}

Enemy::~Enemy()
{
}

void Enemy::initBoard()
{
	for (int i = 0; i < boardX; ++i)
	{
		for (int j = 0; j < boardY; ++j)
		{
			board[i][j] = '.';
		}
	}
}

void Enemy::initShips()
{
	int row = randomInt(0, boardX - 1);
	int column = randomInt(0, boardY - 1);

	board[row][column] = ship;

	int extend = randomInt(0, 4);

	if (extend == 1) //if 1 extend ship 1 column
	{
		board[row][column + 1] = ship;
	}
	else if (extend == 2) //extend ship 2 columns
	{
		board[row][column + 1] = ship;
		board[row][column + 2] = ship;
	}
	else if (extend == 3)
	{
		board[row + 1][column] = ship;
	}
	else
	{
		board[row + 1][column] = ship;
		board[row + 2][column] = ship;
	}
}

void Enemy::grabShipLocations()
{
	for (int i = 0; i < boardX; ++i)
	{
		for (int j = 0; j < boardY; ++j)
		{
			if (board[i][j] == ship)
			{
				shipCount++;
				locations.push_back(location(i, j));
			}
		}
	}
}

void Enemy::draw()
{
	std::cout << "Enter row and column coordinate to fire" << "\n\n";
	std::cout << "  " << "Enemy ship Count: " << shipCount << "\n";
	std::cout << "  ";
	for (int i = 0; i < boardX; i++)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < boardX; ++i)
	{
		std::cout << i << " ";
		for (int j = 0; j < boardY; ++j)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "       Player 2";  
	std::cout << "\n\n";
}

void Enemy::attack(Player &player)
{
	std::cout << "Enemies turn..." << std::endl;
	Sleep(1000);
	int row = randomInt(0, boardX - 1);
	int column = randomInt(0, boardY - 1);

	player.takeHit(row, column);
}

void Enemy::takeHit(int x, int y)
{
	for (std::size_t i = 0; i < locations.size(); i++)
	{
		if (locations[i].x==x && locations[i].y==y) //if hit a ship at the right coordinates
		{
			shipCount--;
			board[x][y] = hit;
			return;
		}
	}
	assert(board[x][y] = miss);
}

bool Enemy::isDead()
{
	return shipCount <= 0 ? true : false;
}
