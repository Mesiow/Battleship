#pragma once
#include <stdlib.h>
#include <random>
#include "Attributes.h"

class Player;


class Enemy : public Attributes
{
public:
	Enemy();
	~Enemy();

public:
	void initBoard();
	void initShips();
	void draw();

public:
	void attack(Player &player);
	void grabShipLocations();
	bool isDead();

public:
	void takeHit(int x, int y);
	
};