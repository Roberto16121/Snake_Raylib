#pragma once
#include "grid.h"
#include "snake.h"
#include "food.h"

class Game
{
public:
	Game();
	void Draw();
	void HandleInput();
	void Move();
	bool dead;
private:
	void Reset();
	void SpawnFood();
	bool IsFoodNext();
	Grid grid;
	Snake snake;
	Food food;
	int dirX, dirY;
	int lastDirX, lastDirY;
};