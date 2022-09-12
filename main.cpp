#include "raylib.h"

int main()
{
    const int windowWidth{768}, windowHeight{768};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPosition{0.0,0.0};
        DrawTextureEx(map, mapPosition, 0.0, 1.0, WHITE);

        EndDrawing();
    }
    CloseWindow();
    
}