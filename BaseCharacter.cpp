#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{

}

Rectangle BaseCharacter::GetCollisionRectangle()
{
    //DrawRectangle(screenPosition.x+ (width/4 * scale), screenPosition.y + (height/4 * scale), (width/2 * scale), (height/2 * scale), BLUE);
    return Rectangle { screenPosition.x + (width/4 * scale), screenPosition.y + (height/4 * scale), (width/2 * scale), (height/2 * scale) };
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

    // draw the player character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle destination{screenPosition.x, screenPosition.y, scale * width, scale * height};
    DrawTexturePro(texture, source, destination, Vector2{}, 0.f, WHITE);
}