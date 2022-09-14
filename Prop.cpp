#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 position, float propScale, Texture2D texture) : worldPosition(position), scale(propScale), texture(texture)
{

}

void Prop::Render(Vector2 playerPosition)
{
    Vector2 screenPosition{ Vector2Subtract(worldPosition, playerPosition)};
    DrawTextureEx(texture, screenPosition, 0.f, scale, WHITE);
}

Rectangle Prop::GetCollisionRectangle(Vector2 playerPosition)
{
    Vector2 screenPosition{ Vector2Subtract(worldPosition, playerPosition)};
    //DrawRectangle(screenPosition.x + (texture.width/4 * scale), screenPosition.y + (texture.height/8 * scale), texture.width/2 * scale, texture.height/2 * scale, WHITE);
    return Rectangle { screenPosition.x + (texture.width/4 * scale), screenPosition.y + (texture.height/8 * scale), texture.width/2 * scale, texture.height/2 * scale,};
    
}