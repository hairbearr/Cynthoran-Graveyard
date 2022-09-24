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
        if(Vector2Length(velocity) < attackRadius || Vector2Length(velocity) > aggroRadius) velocity = {};
        BaseCharacter::Tick(deltaTime);

        if(CheckCollisionRecs(target->GetCollisionRectangle(), GetCollisionRectangle()))
        {
            target->TakeDamage(damagePerSecond*deltaTime);
        }
    }

    Vector2 Enemy::GetScreenPosition()
    {
        return Vector2Subtract(worldPosition, target->GetWorldPosition());
    }