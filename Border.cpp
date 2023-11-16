#include "Border.h"

Border::Border() : GameObject() 
{
    // Default constructor for Border, inheriting from GameObject
}

Border::Border(float initialX, float initialY, float width, float height, std::string name)
    : GameObject(initialX, initialY, width, height, name) 
{
    _hasToCollide = false;
    _isCollidable = true;
}

Border::~Border() 
{
    // Destructor for Border
}
