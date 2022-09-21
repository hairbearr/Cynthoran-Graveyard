#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"


class BaseCharacter
{
    public:
    BaseCharacter();
    Vector2 GetWorldPosition() { return worldPosition; }
    void UndoMovement();
    Rectangle GetCollisionRectangle();
    virtual void Tick(float deltaTime);
    virtual Vector2 GetScreenPosition() = 0;
    

    protected:

    Texture2D
            texture { LoadTexture("characters/Player/Idle_Down.png") } ,
            idle { LoadTexture("characters/Player/Idle_Down.png") },
            walk { LoadTexture("characters/Player/Walk_Right.png") },
            walkUp { LoadTexture("characters/Player/Walk_Up.png") },
            walkDown { LoadTexture("characters/Player/Walk_Down.png") },
            run { LoadTexture("characters/Player/Run_Right.png") },
            runUp { LoadTexture("characters/Player/Run_Up.png") },
            runDown { LoadTexture("characters/Player/Run_Down.png") };

    Vector2 worldPosition{}, worldPositionLastFrame{}, velocity{};
    int frame{}, maxFrames{6};
    float rightLeft{1.f}, runningTime{}, scale{1.f}, updateTime{1.f/12.f}, idleUpdateTime{1.f}, movementSpeed{}, sprintSpeed{1.f}, width{}, height{};
    bool isPlayer{};
    private:
};

#endif