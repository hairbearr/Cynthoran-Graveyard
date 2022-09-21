#include "Character.h"
#include "raymath.h"


Character::Character(int windowWidth, int windowHeight, float playerScale) : windowWidth(windowWidth), windowHeight(windowHeight)
{
    scale = playerScale;
    width = texture.width / maxFrames;
    height = texture.height;
    movementSpeed = 2.75;
    isPlayer = true;
}

Vector2 Character::GetScreenPosition()
{
    return Vector2
    {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight)/ 2.0f - scale * (0.5f * height)
    };
}

void Character::Tick(float deltaTime)
{       
    

    if(IsKeyDown(KEY_W)) { velocity.y -= 1.0; } // up
    if(IsKeyDown(KEY_A)) { velocity.x -= 1.0; } // left
    if(IsKeyDown(KEY_S)) { velocity.y += 1.0; } // down
    if(IsKeyDown(KEY_D)) { velocity.x += 1.0; } // right

    BaseCharacter::Tick(deltaTime);
        
}