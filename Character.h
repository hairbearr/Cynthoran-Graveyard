#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
    public : 
        Character(int windowWidth, int windowHeight, float playerScale);
        virtual void Tick(float deltaTime) override;
        virtual Vector2 GetScreenPosition() override;
        Rectangle GetWeaponCollision(){ return weaponCollisionRectangle; }
        float GetHealth() const { return health; }
        void TakeDamage(float damage);
        
    private :
        int windowWidth{}, windowHeight{};
        Texture2D weapon{LoadTexture("characters/Sword_Flipped.png")};
        Rectangle weaponCollisionRectangle{};
        float health{100.f};        
};

#endif