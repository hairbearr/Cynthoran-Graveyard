#ifndef CHARACTER_H
#define CHARACTER_H

#include "Character.h"
#include "raymath.h"


Character::Character(int windowWidth, int windowHeight, float playerScale)
{
    scale = playerScale;
    width = texture.width / maxFrames;
    height = texture.height;
    screenPosition =
    {
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight)/ 2.0f - scale * (0.5f * height)
    };
}

void Character::Tick(float deltaTime)
{       
    BaseCharacter::Tick(deltaTime);

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

        if(IsKeyDown(KEY_LEFT_SHIFT))
        {
            movementSpeed = 2.75 + sprintSpeed;
            updateTime = 1.f/6.f;
            if(direction.y < 0 ) { texture = runUp; }
            else if (direction.y > 0) { texture = runDown; }
            else { texture = run; }
        }
        else
        {
            updateTime = 1.f/12.f;
            movementSpeed = 2.75;
            if(direction.y < 0 ) { texture = walkUp; }
            else if (direction.y > 0) { texture = walkDown; }
            else { texture = walk; }
        }
    }
    else
    {
        texture = idle;
        updateTime = idleUpdateTime;
    }
        
}

#endif