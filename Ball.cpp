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


    //sf::Vector2f setorigin(radius / 2.f, radius / 2.f);
    //this->GetShape()->setOrigin(setorigin);
}



Ball::~Ball() {
    
}
