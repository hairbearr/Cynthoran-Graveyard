#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
    public : 
        Character(int windowWidth, int windowHeight, float playerScale);
        void Tick(float deltaTime);
        
    private :
        
};