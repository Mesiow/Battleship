#pragma once
#include "Player.h"
#include "Enemy.h"
#include <iostream>

class Game
{

public:
	Game();
	~Game();
	Game(const Game &other) = delete;
	Game(Game &&other) = delete;
	Game &operator=(const Game &other) = delete;

public:
	void run();
	void draw();
	void clear();
	void input();
	void logic();
	void exit();

public:
	bool isRunning()const { return running; }

private:
	Player player;
	Enemy enemy;
	bool running = true;

};