#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 position, float propScale, Texture2D texture);

private:
    Texture2D texture{};
    Vector2 worldPosition{};
    float scale{};
};