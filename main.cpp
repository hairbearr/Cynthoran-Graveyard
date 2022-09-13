#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{768}, windowHeight{768};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");
    Vector2 mapPosition{0.0,0.0};

    Texture2D player = LoadTexture("characters/Player/Idle_Down.png");
    Vector2 playerPosition{ (float)windowWidth/2.0f - 4.0f * (0.5f * (float)player.width/6.0f), (float)windowHeight/2.0f - 4.0f * (0.5f * (float)player.height)};

    float playerMovementSpeed{4.0};
    float playerScale{1.25};

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

        // draw the map
        DrawTextureEx(map, mapPosition, 0.0, 1.0, WHITE);

        // draw the player character
        Rectangle source{0.f, 0.f, (float)player.width/6.f, (float)player.height};
        Rectangle destination{playerPosition.x, playerPosition.y, playerScale * (float)player.width/6.0f, playerScale * (float)player.height};
        DrawTexturePro(player, source, destination, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();
    
}