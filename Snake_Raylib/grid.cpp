#include "grid.h"
#include <iostream>
Grid::Grid()
{
	cellSize = 31;
	width = 15;
	height = 15;

}

void Grid::Draw(int wid, int hei)
{
	int offX, offY;
	offX = wid / 2;
	offX = offX - (cellSize+2) * (width / 2);
	offY = hei / 2;
	offY = offY - (cellSize+2) * (height / 2);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			DrawRectangle(offX + j * cellSize + 1, offY + i * cellSize + 1, cellSize - 1, cellSize - 1, LIGHTGRAY);
		}
	}
}

void Grid::Init(std::deque<Vector2> pos, Vector2 food)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	for (Vector2 item : pos)
	{
		grid[(int)item.x][(int)item.y] = 1;
	}
	grid[(int)food.x][(int)food.y] = 2;
}

