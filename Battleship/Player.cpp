#include "Player.h"
#include <iostream>
#include "Utils.h"
#include "Enemy.h"

Player::Player()
{
	initBoard();

	for(int i=0; i<6; ++i)
		initShips();
}

Player::~Player()
{

}

void Player::initBoard()
{
	for (int i = 0; i < 10; i++)
		std::cout << "\n";

	for (int i = 0; i < boardX; ++i)
	{
		for (int j = 0; j < boardY; ++j)
		{
			board[i][j] = '.';  //create board
		}
	}
}

void Player::initShips()
{
	int row=randomInt(0, boardX - 1);
	int column=randomInt(0, boardY - 1);

	board[row][column] = ship;

	int extend = randomInt(0, 4);

	if ( extend == 1) //if 1 extend ship 1 column
	{
		board[row][column + 1] = ship;
	}
	else if(extend==2) //extend ship 2 columns
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

void Player::draw()
{
	std::cout << " ";
	for (int count = 0; count < boardX; count++)
	{
		std::cout << ' ' << count;
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
	std::cout << "    Player 1(You)";
}

void Player::attack(Enemy &enemy)
{
	int x, y;
	std::cout << "\n\n";
	std::cout << "Your turn , Enter coordinates: ";
	std::cin >> x;
	std::cin >> y;

	enemy.takeHit(x, y);
}

bool Player::isDead()
{
	int shipCount = 0;
	for (int i = 0; i < boardX; ++i)
	{
		for (int j = 0; j < boardY; ++j)
		{
			if (board[i][j] == ship)
				shipCount++;
		}
	}

	return shipCount <= 0 ? true : false;
}

void Player::takeHit(int x, int y)
{
	if (board[x][y] == ship)
		board[x][y] = hit;
	else
		board[x][y] = miss;
}
