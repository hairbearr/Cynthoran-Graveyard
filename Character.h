#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
    public : 
        Character(int windowWidth, int windowHeight, float playerScale);
        virtual void Tick(float deltaTime) override;
        
    private :
        
};