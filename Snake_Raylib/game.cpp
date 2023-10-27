#include "game.h"
#include <iostream>
#include <deque>

Game::Game()
{
	grid = Grid();
	snake = Snake();
	dirX = lastDirX = -1;
	dirY = lastDirY = 0;
	dead = false;
	SpawnFood();
}

void Game::Draw()
{
	int width = GetScreenWidth();
	int height = GetScreenHeight();
	if (width < 465 && height < 600)
	{
		SetWindowSize(465, 600);
		width = 465;
		height = 600;
	}
	else if (width < 465)
	{
		SetWindowSize(465, height);
		width = 465;
	}
	else if (height < 600)
	{
		SetWindowSize(width, 600);
		height = 600;
	}
	grid.Draw(width, height);
	snake.Draw(width, height);
	food.Draw(width, height);
	if (snake.dead)
		dead = true;
}

void Game::Move()
{
	if (snake.dead)
	{
		Reset();
		return;
	}
	if (IsFoodNext())
	{
		snake.FoodNext();
		food.~Food();
		SpawnFood();
	}
	snake.Move(dirX, dirY);
	lastDirX = dirX;
	lastDirY = dirY;
	std::deque<Vector2> newPos = snake.positions;
	newPos.push_back(snake.head);
	Vector2 foodPos = Vector2{ 0,0 };
	foodPos.x = food.posX;
	foodPos.y = food.posY;
	grid.Init(newPos, foodPos);
}

void Game::Reset()
{
	dirX = lastDirX = -1;
	dirY = lastDirY = 0;
	dead = false;
	food.~Food();
	snake.Reset();
	food = Food();
	SpawnFood();
}

void Game::SpawnFood()
{
	std::deque<Vector2> newPos = snake.positions;
	newPos.push_back(snake.head);
	food = Food();
	food.GetSnakePos(newPos);
}

bool Game::IsFoodNext()
{
	if (snake.head.x + dirX == food.posX && snake.head.y + dirY == food.posY)
		return true;
	return false;
}

void Game::HandleInput()
{
	
	int keyPressed = GetKeyPressed();
	
	if (dead && keyPressed != 0)
	{
		Move();
		return;
	}
	
	switch (keyPressed)
	{
	case KEY_W:
	case KEY_UP:
	{
		dirX = 0;
		dirY = -1;
	}break;
	case KEY_S:
	case KEY_DOWN:
	{
		dirX = 0;
		dirY = 1;
	}break;
	case KEY_D:
	case KEY_RIGHT:
	{
		dirX = 1;
		dirY = 0;
	}break;
	case KEY_A:
	case KEY_LEFT:
	{
		dirX = -1;
		dirY = 0;
	}break;
	default:
		break;
	}

	if (dirX == 1)
	{
		if (lastDirX == -1)
			dirX = lastDirX;
	}
	else if (dirX == -1)
	{
		if (lastDirX == 1)
			dirX = lastDirX;
	}
	if (dirY == 1)
	{
		if (lastDirY == -1)
			dirY = lastDirY;
	}
	else if (dirY == -1)
	{
		if (lastDirY == 1)
			dirY = lastDirY;
	}
}
