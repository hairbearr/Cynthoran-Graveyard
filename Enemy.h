#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{

public:
    Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture);
    void Tick(float deltaTime);
    

private:

};
