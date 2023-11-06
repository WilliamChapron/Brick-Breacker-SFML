#include "PhysicalGameObject.h"

PhysicalGameObject::PhysicalGameObject() : GameObject() {
    _speed = 0;
    _orientation = sf::Vector2f(0, 0);
}

PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH) : GameObject(initialX, initialY, sizeW, sizeH) {
    _speed = 0;
    _orientation = sf::Vector2f(0, 0);
}

void PhysicalGameObject::Move(float dx, float dy) {
    float dx = _speed * 1
    float dy = 

    _position.x += _speed * _orientation.x * dx;
    _position.y += _speed  _orientation.y  dy;
}

sf::Vector2f PhysicalGameObject::GetOrientation() const {
    return _orientation;
}

int PhysicalGameObject::GetSpeed() const {
    return _speed;
}

void PhysicalGameObject::SetOrientation(float x, float y) {
    _orientation.x = x;
    _orientation.y = y;
}

void PhysicalGameObject::SetSpeed(int speed) {
    _speed = speed;
}
