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