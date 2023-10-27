#pragma once
#include <raylib.h>
#include <deque>
class Snake
{
public:
	Snake();
	~Snake();
	void Draw(int wid, int hei);
	void FoodNext();
	void Move(int dirX, int dirY);
	void Reset();
	std::deque<Vector2> positions;
	Vector2 head;
	
	bool dead;
private:
	bool InsideMove();
	bool HitHimself();
	void Init();
	bool ToAdd;
	int cellSize;
	int width, height;
};