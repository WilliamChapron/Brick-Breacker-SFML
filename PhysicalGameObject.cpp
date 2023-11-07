#include "PhysicalGameObject.h"
#include <iostream>

PhysicalGameObject::PhysicalGameObject() : GameObject() {
    _speed = 10;
    _orientation = sf::Vector2f(0, 0);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH) : GameObject(initialX, initialY, sizeW, sizeH) {
    _speed = 10;
    _orientation = sf::Vector2f(0, -1);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int radius) : GameObject(initialX, initialY, radius) {
    _speed = 10;
    _orientation = sf::Vector2f(1, -1);
}



void PhysicalGameObject::Move() { // #TODO - Add DeltaTime

    _position.x += (_speed * _orientation.x) * GameNamespace::GameManager::GetDeltaTime();
    _position.y += (_speed * _orientation.y) * GameNamespace::GameManager::GetDeltaTime();


    //std::cout << _position.x<< std::endl;
    //std::cout << _position.y << std::endl;

    if (ptr_shape != nullptr) { 
        ptr_shape->setPosition(_position); 
    }
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


