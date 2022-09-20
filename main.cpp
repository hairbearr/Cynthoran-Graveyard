#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
    const int windowWidth{854}, windowHeight{480};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");
    Vector2 mapPosition{0.0,0.0};
    const float mapScale{1.f};

    Character adventurer { windowWidth, windowHeight, 1.f };

    // Enemy enemies[1]
    // {
    //     Enemy {Vector2{300.f, 400.f}, 1.f, LoadTexture("characters/Slime/slime_idle.png"), LoadTexture("characters/Slime/slime_run.png") }
    // };

    Prop props[2]
    {
        Prop {Vector2{600.f,300.f}, 1.f, LoadTexture("props/Rock_1.png")},
        Prop {Vector2{400.f,500.f}, 1.f, LoadTexture("props/Fountain.png")}
    };

    Enemy slime
    {
        Vector2{300.f, 400.f},
        1.f,
        LoadTexture("characters/Slime/slime_idle.png"),
        LoadTexture("characters/Slime/slime_run.png")
    };
    slime.setTarget(&adventurer);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // mapPosition = Vector2Negate(adventurer.GetWorldPosition()); works just the same way as scaling the world position by negative one
        mapPosition = Vector2Scale(adventurer.GetWorldPosition(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPosition, 0.0, mapScale, WHITE);
        
        // draw the props
        for(auto prop : props)
        {
            prop.Render(adventurer.GetWorldPosition());
        }

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

        // check prop collisions
        for ( auto prop : props)
        {
            if(CheckCollisionRecs(prop.GetCollisionRectangle(adventurer.GetWorldPosition()), adventurer.GetCollisionRectangle()))
            {
                adventurer.UndoMovement();
            }
        }

        // for(auto enemy : enemies)
        // {
        //     enemy.Tick(GetFrameTime());
        // }

        slime.Tick(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();
    
}