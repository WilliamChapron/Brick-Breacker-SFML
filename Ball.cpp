#include "Ball.h"

Ball::Ball() : PhysicalGameObject() {

}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name) 
{
    _isCollidable = true;
}

Ball::~Ball() {
    
}
