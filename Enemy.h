#include "raylib.h"

class Enemy
{

public:
    Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture);
    Vector2 GetWorldPosition() {return worldPosition; }
    void UndoMovement();
    void Tick(float deltaTime);
    Rectangle GetCollisionRectangle();

private:
    Texture2D
        texture {LoadTexture("characters/Slime/slime_idle.png")},
        idle {LoadTexture("characters/Slime/slime_idle.png")},
        run {LoadTexture("characters/Slime/slime_run.png")};

    Vector2 screenPosition{}, worldPosition{}, worldPositionLastFrame{};
    int frame{}, maxFrames{6};
    float rightLeft{1.f}, runningTime{}, scale{1.f}, updateTime{1.f/12.f}, movementSpeed{}, width{}, height{};

};
