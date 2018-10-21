#include "Game.h"

Game::Game()
	:player(), enemy()
{

}

Game::~Game()
{
	
}

void Game::run()
{
	draw();
	input();
	logic();
	clear();
}

void Game::draw()
{
	enemy.draw();
	player.draw();
}

void Game::clear()
{
	system("cls");
}

void Game::input()
{
	player.attack(enemy);
	enemy.attack(player);
}

void Game::logic()
{
	if (player.isDead())
	{
		std::cout << "Player 2 wins!" << std::endl;
		exit();
	}
	else if (enemy.isDead())
	{
		std::cout << "Player 1 (You) wins!" << std::endl;
		exit();
	}
}

void Game::exit()
{
	system("pause");
	running = false;
}
