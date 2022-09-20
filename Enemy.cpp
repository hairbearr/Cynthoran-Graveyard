#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture)
    {
        worldPosition = position;
        scale = enemyScale;
        texture = idleTexture;
        idle = idleTexture;
        run = runTexture;

        width = texture.width / maxFrames;
        height = texture.height;
        movementSpeed = 1.75f;
    }

void Enemy::Tick(float deltaTime)
    {

        // Get toTarget
        Vector2 toTarget = Vector2Subtract(target->GetScreenPosition(), screenPosition);
        // Normalize toTarget
        toTarget = Vector2Normalize(toTarget);
        // Multiply toTarget by Speed
        toTarget = Vector2Scale(toTarget, movementSpeed);
        // Move Enemy (set world position)
        worldPosition = Vector2Add(worldPosition, toTarget);

        screenPosition = Vector2Subtract(worldPosition, target->GetWorldPosition());
        BaseCharacter::Tick(deltaTime);
    }