#include <raylib.h>
#include "game.h"
#include <iostream>

double LastTime;
bool MoveSnake(double threshold)
{
    double currentTime = GetTime();
    if (currentTime - LastTime >= threshold)
    {
        LastTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    const int screenWidth = 465;
    const int screenHeight = 600;
    SetTraceLogLevel(TraceLogLevel::LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Tetris_Raylib");

    Texture2D texture = LoadTexture("Resources/Smurf.png");
    Font font = LoadFontEx("Roboto-Regular.ttf", 64, 0, 0);
     
    SetTargetFPS(60);

    Game game = Game();
    LastTime = GetTime();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        game.HandleInput();

        if (MoveSnake(0.4) && !game.dead)
        {
            game.Move();
        }
        game.Draw();
        DrawTexture(texture, 1204,25, WHITE);

        if(game.dead)
            DrawTextEx(font, "GameOver", { GetScreenWidth()/2.5f,GetScreenHeight() - 50.0f}, 38, 2, WHITE);

        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
}