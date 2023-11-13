#include "Ball.h"

Ball::Ball() : PhysicalGameObject() {
    // Configuration supplémentaire si nécessaire
}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name) {
    // Configuration supplémentaire spécifique à la classe Ball
    _speed = 100;
    _moveState = 1;
    _isCollidable = true;

    sf::Vector2f setorigin(radius / 2.f, radius / 2.f);
    this->GetShape()->setOrigin(setorigin);
}

Ball::~Ball() {
}

