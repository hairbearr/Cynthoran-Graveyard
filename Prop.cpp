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