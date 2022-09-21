#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

Rectangle BaseCharacter::GetCollisionRectangle()
{
    //DrawRectangle(screenPosition.x+ (width/4 * scale), screenPosition.y + (height/4 * scale), (width/2 * scale), (height/2 * scale), BLUE);
    return Rectangle { GetScreenPosition().x + (width/4 * scale), GetScreenPosition().y + (height/4 * scale), (width/2 * scale), (height/2 * scale) };
}

void BaseCharacter::UndoMovement()
{
    worldPosition = worldPositionLastFrame;
}

void BaseCharacter::Tick(float deltaTime)
{
    worldPositionLastFrame = worldPosition;
    
    // update animation frame
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if(frame>maxFrames) frame = 0;
    }

    if(Vector2Length(velocity) != 0.0)
    {
        // set world position to world position plus velocity
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), movementSpeed));
        
        // this is the same as the following if/else statement using the ternary operator
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        // if(direction.x <0.f) { rightLeft = -1.f; }
        // else{ rightLeft = 1.f; }

        if(isPlayer)
        {
            if(IsKeyDown(KEY_LEFT_SHIFT))
            {
                movementSpeed = 2.75 + sprintSpeed;
                updateTime = 1.f/6.f;
                if(velocity.y < 0 ) { texture = runUp; }
                else if (velocity.y > 0) { texture = runDown; }
                else { texture = run; }
            }
            else
            {
                updateTime = 1.f/12.f;
                movementSpeed = 2.75;
                if(velocity.y < 0 ) { texture = walkUp; }
                else if (velocity.y > 0) { texture = walkDown; }
                else { texture = walk; }
            }
            
        }
        else
        {
            texture=run;
            updateTime = 1.f/12.f;
        }
        
    }
    else
    {
        texture = idle;
        updateTime = idleUpdateTime;
    }
    velocity = {};

    // draw the player character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle destination{GetScreenPosition().x, GetScreenPosition().y, scale * width, scale * height};
    DrawTexturePro(texture, source, destination, Vector2{}, 0.f, WHITE);
}