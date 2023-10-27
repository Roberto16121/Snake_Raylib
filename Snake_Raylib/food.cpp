#include "food.h"
#include <random>

Food::Food()
{
	cellsize = 31;
	posX = 0;
	posY = 0;
	width = 15;
	height = 15;
}

Food::~Food()
{
}


void Food::Draw(int wid, int hei)
{
	int offX, offY;
	offX = wid / 2;
	offX = offX - (cellsize + 2) * (width / 2);
	offY = hei / 2;
	offY = offY - (cellsize + 2) * (height / 2);
	DrawRectangle(offX + posX * cellsize + 1, offY + posY * cellsize + 1, cellsize - 1, cellsize - 1, RED);
}

void Food::GetSnakePos(std::deque<Vector2> pos)
{
	Vector2 foodPos = GetRandomPos(pos);
	posX = (int)foodPos.x;
	posY = (int)foodPos.y;
}

Vector2 Food::GetRandomPos(std::deque<Vector2> pos)
{
	Vector2 newPos = Vector2{ 0,0 };
	newPos.x = rand() % 15;
	newPos.y = rand() % 15;
	while (!LegalSpawn(newPos.x, newPos.y, pos))
	{
		newPos.x = rand() % 15;
		newPos.y = rand() % 15;
	}
	return newPos;
}

bool Food::LegalSpawn(int posX, int posY, std::deque<Vector2> snakePos)
{
	if (snakePos.size() == 0)
		return true;
	for (Vector2 item : snakePos)
	{
		if (item.x == posX || item.y == posY)
			return false;
	}
	return true;
}
