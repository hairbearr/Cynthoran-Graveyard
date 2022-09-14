#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth{854}, windowHeight{480};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");
    Vector2 mapPosition{0.0,0.0};
    const float mapScale{1.f};

    Character adventurer { windowWidth, windowHeight, 1.f };


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // mapPosition = Vector2Negate(adventurer.GetWorldPosition()); works just the same way as scaling the world position by negative one
        mapPosition = Vector2Scale(adventurer.GetWorldPosition(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPosition, 0.0, mapScale, WHITE);
        
        adventurer.Tick(GetFrameTime());
        // check map bounds
        if  (
                adventurer.GetWorldPosition().x < 0.f - (windowWidth/2) ||
                adventurer.GetWorldPosition().y < 0.f - (windowHeight/2) ||
                adventurer.GetWorldPosition().x + windowWidth > (map.width + (windowWidth/2)) * mapScale ||
                adventurer.GetWorldPosition().y + windowHeight > ((map.height + (windowHeight/2)) * mapScale)
            )
        {
            adventurer.UndoMovement();
        }

        EndDrawing();
    }
    CloseWindow();
    
}