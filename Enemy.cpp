#include "Enemy.h"

Enemy::Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture) :
        worldPosition(position),
        scale(enemyScale),
        texture(idleTexture),
        idle(idleTexture),
        run(runTexture)
    {
        width = texture.width / maxFrames;
        height = texture.height;
    }

void Enemy::Tick(float deltaTime)
    {
        worldPositionLastFrame = worldPosition;

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

void Enemy::UndoMovement()
{
    worldPosition = worldPositionLastFrame;
}

Rectangle Enemy::GetCollisionRectangle()
{
    return Rectangle { screenPosition.x + (width/4 * scale), screenPosition.y + (height/4 * scale), (width/2 * scale), (height/2 * scale) };
}