#include "raylib.h"
#include "raymath.h"

class Character
{
    public : 
        Vector2 GetWorldPosition() { return worldPosition; }
        void SetScreenPosition(int windowWidth, int windowHeight);
        void Tick(float deltaTime);


    private :
        Texture2D
            texture { LoadTexture("characters/Player/Idle_Down.png") } ,
            idle { LoadTexture("characters/Player/Idle_Down.png") },
            run { LoadTexture("characters/Player/Walk_Right.png") },
            runUp { LoadTexture("characters/Player/Walk_Up.png") },
            runDown { LoadTexture("characters/Player/Walk_Down.png") };
        Vector2 screenPosition, worldPosition;
        float rightLeft{1.f}, runningTime{};
        int frame{};
        const int maxFrames{6};
        float updateTime{1.f/12.f}, idleUpdateTime{1.f};
        const float movementSpeed{4.f};
};

void Character::SetScreenPosition(int windowWidth, int windowHeight)
{
    screenPosition = 
    {
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)texture.width/6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)texture.height)
    };
}

void Character::Tick(float deltaTime)
{
     Vector2 direction{};
        if(IsKeyDown(KEY_W)) { direction.y -= 1.0; } // up
        if(IsKeyDown(KEY_A)) { direction.x -= 1.0; } // left
        if(IsKeyDown(KEY_S)) { direction.y += 1.0; } // down
        if(IsKeyDown(KEY_D)) { direction.x += 1.0; } // right

        if(Vector2Length(direction) != 0.0)
        {
            // set world position to world position plus direction
            worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(direction), movementSpeed));
            
            // this is the same as the following if/else statement using the ternary operator
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            // if(direction.x <0.f) { rightLeft = -1.f; }
            // else{ rightLeft = 1.f; }

            updateTime = 1.f/12.f;

            if(direction.y < 0 ) { texture = runUp; }
            else if (direction.y > 0) { texture = runDown; }
            else { texture = run; }
        }
        else
        {
            texture = idle;
            updateTime = idleUpdateTime;
        }

        // update animation frame
        runningTime += deltaTime;
        if(runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if(frame>maxFrames) frame = 0;
        }
}

int main()
{
    const int windowWidth{768}, windowHeight{768};
    const char * windowTitle{"Cynthoran Graveyard"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    Texture2D map = LoadTexture("tilemaps/Graveyard.png");
    Vector2 mapPosition{0.0,0.0};

    Texture2D player = LoadTexture("characters/Player/Idle_Down.png");
    Vector2 playerPosition{ (float)windowWidth/2.0f - 4.0f * (0.5f * (float)player.width/6.0f), (float)windowHeight/2.0f - 4.0f * (0.5f * (float)player.height)};
    Texture2D playerIdle = LoadTexture("characters/Player/Idle_Down.png");
    Texture2D playerRun = LoadTexture("characters/Player/Walk_Right.png");
    Texture2D playerRunUp = LoadTexture("characters/Player/Walk_Up.png");
    Texture2D playerRunDown = LoadTexture("characters/Player/Walk_Down.png");


    // 1 : facing right, -1 : facing left
    float rightLeft{1.f};

    float playerMovementSpeed{4.0};
    float playerScale{1.25};

    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float idleUpdateTime{1.f};
    float updateTime{1.f/12.f};

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
            if(direction.y < 0 ) { player = playerRunUp; }
            else if (direction.y > 0) { player = playerRunDown; }
            else { player = playerRun; }
            
            
            // set map position to map position minus direction
            
            mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), playerMovementSpeed));
            
            // this is the same as the following if/else statement using the ternary operator
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            
            // if(direction.x <0.f) { rightLeft = -1.f; }
            // else{ rightLeft = 1.f; }

            updateTime = 1.f/12.f;
        }
        else
        {
            player = playerIdle;
            updateTime = idleUpdateTime;
        }

        // draw the map
        DrawTextureEx(map, mapPosition, 0.0, 1.0, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if(runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if(frame>maxFrames) frame = 0;
        }

        // draw the player character
        Rectangle source{frame * (float)player.width/6.f, 0.f, rightLeft * (float)player.width/6.f, (float)player.height};
        Rectangle destination{playerPosition.x, playerPosition.y, playerScale * (float)player.width/6.0f, playerScale * (float)player.height};
        DrawTexturePro(player, source, destination, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();
    
}