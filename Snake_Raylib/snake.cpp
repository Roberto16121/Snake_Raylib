#include "snake.h"
#include <random>
#include <iostream>

Snake::Snake()
{
	Init();
}

Snake::~Snake()
{
	positions.clear();
}

void Snake::Draw(int wid, int hei)
{
	int offX, offY;
	offX = wid / 2;
	offX = offX - (cellSize + 2) * (width / 2);
	offY = hei / 2; 
	offY = offY - (cellSize + 2) * (height / 2);
	DrawRectangle(offX + head.x * cellSize + 1, offY + head.y * cellSize + 1, cellSize - 1, cellSize-1, BLACK);
	for (Vector2 item : positions)
	{
		DrawRectangle(offX + item.x * cellSize + 1, offY + item.y * cellSize + 1, cellSize - 1, cellSize - 1, DARKGRAY);
	}
}

void Snake::FoodNext()
{
	ToAdd = true;
}



void Snake::Move(int dirX, int dirY)
{
	head.x += dirX;
	head.y += dirY;

	if (!InsideMove())
	{
		dead = true;
		head.x -= dirX;
		head.y -= dirY;
		return;
	}
	if (HitHimself())
	{
		dead = true;
		head.x -= dirX;
		head.y -= dirY;
		return;
	}

	if (ToAdd)
	{
		int x = head.x - dirX;
		int y = head.y - dirY;
		Vector2 newPos = Vector2{0, 0};
		newPos.x = x;
		newPos.y = y;
		positions.push_front(newPos);
		ToAdd = false;
	}
	else
	{
		int x = head.x - dirX;
		int y = head.y - dirY;
		
		Vector2 oldPos;
		if (positions.size() != 0)
		{
			oldPos = positions[0];
			positions[0].x = x;
			positions[0].y = y;

			for (int i = 1; i < positions.size(); i++)
			{
				Vector2 current = positions[i];
				positions[i] = oldPos;
				oldPos = current;

			}
		}
	}
	


	

}

void Snake::Reset()
{
	positions.clear();
	Init();
}

bool Snake::InsideMove()
{
	if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height)
		return false;

	return true;
}

bool Snake::HitHimself()
{
	for (Vector2 item : positions)
	{
		if (head.x == item.x && head.y == item.y)
			return true;
	}
	return false;
}

void Snake::Init()
{
	int x = rand() % 10;
	int y = rand() % 10;
	if (x < 5)
		x = 5;
	if (y < 5)
		y = 5;
	head.x = x;
	head.y = y;
	cellSize = 31;
	width = 15;
	height = 15;
	dead = false;
	ToAdd = false;
}
