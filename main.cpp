#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{768}, windowHeight{768};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");
    Vector2 mapPosition{0.0,0.0};

    float playerMovementSpeed{4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Vector2 direction{};
        if(IsKeyDown(KEY_W)) { direction.y -= 1.0; } // up
        if(IsKeyDown(KEY_A)) { direction.x -= 1.0; } // left
        if(IsKeyDown(KEY_S)) { direction.y += 1.0; } // down
        if(IsKeyDown(KEY_D)) { direction.x += 1.0; } // right

        if(Vector2Length(direction) != 0.0)
        {
            // set map position to map position minus direction
            
            mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), playerMovementSpeed));
        }

        DrawTextureEx(map, mapPosition, 0.0, 1.0, WHITE);

        EndDrawing();
    }
    CloseWindow();
    
}