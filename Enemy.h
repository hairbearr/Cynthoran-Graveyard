#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{

public:
    Enemy(Vector2 position, float enemyScale, Texture2D idleTexture, Texture2D runTexture);
    virtual void Tick(float deltaTime) override;
    void setTarget(Character* character) { target = character; }
    virtual Vector2 GetScreenPosition() override;

private:
    Character* target;
    float damagePerSecond{10.f};
};
