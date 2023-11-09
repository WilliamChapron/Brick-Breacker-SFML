#include "Ball.h"
#include "GameObject.h"
#include <string>


Ball::Ball() : PhysicalGameObject() {

}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name) 
{
    _speed = 100;
    _moveState = 1;
    _isCollidable = true;
}

Ball::~Ball() {
    
}
