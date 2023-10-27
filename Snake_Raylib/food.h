#pragma once
#include "raylib.h"
#include <deque>
class Food
{
public:
	Food();
	~Food();
	void Draw(int wid, int hei);
	void GetSnakePos(std::deque<Vector2> pos);
	int posX, posY;
private:
	int cellsize;
	Vector2 GetRandomPos(std::deque<Vector2> pos);
	bool LegalSpawn(int posX, int posY, std::deque<Vector2> snakePos);
	int width, height;
};