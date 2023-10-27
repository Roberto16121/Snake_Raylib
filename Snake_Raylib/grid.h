#pragma once
#include <raylib.h>
#include <deque>
class Grid
{
public:
	Grid();
	void Draw(int wid, int hei);
	void Init(std::deque<Vector2> pos, Vector2 food);
	int grid[40][40];
	int cellSize;
private:
	int width;
	int height;


};