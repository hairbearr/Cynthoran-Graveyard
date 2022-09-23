#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture)
    {
        worldPosition = position;
        scale = enemyScale;
        texture = idleTexture;
        idle = idleTexture;
        run = runTexture;
        isPlayer = false;

        width = texture.width / maxFrames;
        height = texture.height;
        movementSpeed = 1.75f;
    }

void Enemy::Tick(float deltaTime)
    {
        if(!GetAlive()) { return; }

        // Get toTarget
        velocity = Vector2Subtract(target->GetScreenPosition(), GetScreenPosition());
        BaseCharacter::Tick(deltaTime);
    }

    Vector2 Enemy::GetScreenPosition()
    {
        return Vector2Subtract(worldPosition, target->GetWorldPosition());
    }