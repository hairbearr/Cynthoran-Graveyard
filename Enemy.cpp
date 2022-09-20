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
    }

void Enemy::Tick(float deltaTime)
    {

        screenPosition = Vector2Subtract(worldPosition, target->GetWorldPosition());

        BaseCharacter::Tick(deltaTime);


    }