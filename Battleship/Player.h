#pragma once
#include <stdlib.h>
#include "Attributes.h"

class Enemy;

class Player : public Attributes
{

public:
	Player();
	~Player();

public:
	void initBoard();
	void initShips();
	void draw();

public:
	void attack(Enemy &enemy);
	bool isDead();

public:
	void takeHit(int x, int y);

};