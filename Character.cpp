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
    if(!GetAlive()) { return; }

    if(IsKeyDown(KEY_W)) { velocity.y -= 1.0; } // up
    if(IsKeyDown(KEY_A)) { velocity.x -= 1.0; } // left
    if(IsKeyDown(KEY_S)) { velocity.y += 1.0; } // down
    if(IsKeyDown(KEY_D)) { velocity.x += 1.0; } // right

    BaseCharacter::Tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if(rightLeft > 0.f)
    {
        origin = {0.f, weapon.height*scale+(weapon.height/3.2f)};
        offset = {35.f, 55.f};
        weaponCollisionRectangle = { GetScreenPosition().x + offset.x , GetScreenPosition().y + offset.y - weapon.height * (scale/.8f), weapon.width * (scale/1.5f), weapon.height * (scale/1.5f)};


        // if I was just rotating the weapon, and not messing with scale and stuff, I would use
        // if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) ? rotation = 35.f : rotation = 0.f;
        // which would read if left mouse button is down is true, rotation = 35.f, if it is false, rotation = 0.f. This is a Ternary Operator

        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            origin = {0.f, weapon.height*scale+(weapon.height/3.f)};
            offset = {20.f, 55.f};
            weaponCollisionRectangle = { GetScreenPosition().x + offset.x + (weapon.width * (scale/1.7f)) , GetScreenPosition().y + offset.y - weapon.height * (scale), weapon.width * (scale/1.5f), weapon.height * (scale/1.5f)};
            rotation = 35.f;
        }
        else
        {
            rotation = 0.f;
        }
    }
    else
    {
        origin = {(weapon.width*scale)-(weapon.width/2.f), weapon.height*scale+(weapon.height/3.2f)};
        offset = {25.f, 55.f};
        weaponCollisionRectangle = { GetScreenPosition().x + offset.x - (weapon.width * (scale/1.9f)) , GetScreenPosition().y + offset.y - weapon.height * (scale/.8f), weapon.width * (scale/1.5f), weapon.height * (scale/1.5f)};
        
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            origin = {(weapon.width * scale) - (weapon.width/2.f), (weapon.height * scale)+(weapon.height/3.f)};
            offset = {40.f, 55.f};
            weaponCollisionRectangle = { GetScreenPosition().x - offset.x + (weapon.width * (scale/.7f)), GetScreenPosition().y + offset.y - weapon.height * (scale), weapon.width * (scale/1.5f), weapon.height * (scale/1.5f)};
            rotation = -35.f;
        }
        else
        {
            rotation = 0.f;
        }
    }
        
    // draw sword
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle destination{GetScreenPosition().x + offset.x, GetScreenPosition().y + offset.y, weapon.width * (scale/1.5f), weapon.height * (scale/1.5f)};
    DrawTexturePro(weapon, source, destination, origin, rotation, WHITE);

    DrawRectangleLines(weaponCollisionRectangle.x, weaponCollisionRectangle.y, weaponCollisionRectangle.width, weaponCollisionRectangle.height, RED);
}

void Character::TakeDamage(float damage)
{
    health -= damage;
    if(health <=0.f)
    {
        SetAlive(false);
    }
}