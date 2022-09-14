#include "raylib.h"

class Character
{
    public : 
        Character(int windowWidth, int windowHeight, float playerScale);
        Vector2 GetWorldPosition() { return worldPosition; }
        void UndoMovement();
        void Tick(float deltaTime);
        Rectangle GetCollisionRectangle();
        
    private :
        Texture2D
            texture { LoadTexture("characters/Player/Idle_Down.png") } ,
            idle { LoadTexture("characters/Player/Idle_Down.png") },
            walk { LoadTexture("characters/Player/Walk_Right.png") },
            walkUp { LoadTexture("characters/Player/Walk_Up.png") },
            walkDown { LoadTexture("characters/Player/Walk_Down.png") },
            run { LoadTexture("characters/Player/Run_Right.png") },
            runUp { LoadTexture("characters/Player/Run_Up.png") },
            runDown { LoadTexture("characters/Player/Run_Down.png") };
        Vector2 screenPosition{}, worldPosition{}, worldPositionLastFrame{};
        int frame{}, maxFrames{6};
        float rightLeft{1.f}, runningTime{}, scale{1.f}, updateTime{1.f/12.f}, idleUpdateTime{1.f}, movementSpeed{2.75f}, sprintSpeed{2.f}, width{}, height{};
};