#include "Canon.h"

Canon::Canon() : PhysicalGameObject() {
}

Canon::Canon(float initialX, float initialY, float width, float height, std::string name) : PhysicalGameObject(initialX, initialY, width, height, name)
{
    _isCollidable = false;
}

Canon::~Canon() {
    
}

