
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"





PhysicalGameObject::PhysicalGameObject() : GameObject() {
    _moveState = 0;
    _speed = 10;
    _orientation = sf::Vector2f(0, 0);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) : GameObject(initialX, initialY, sizeW, sizeH, name) {
    _moveState = 0;
    _speed = 10;
    _orientation = sf::Vector2f(0, -1);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int radius, std::string name) : GameObject(initialX, initialY, radius, name) {
    _moveState = 0;
    _speed = 10;
    _orientation = sf::Vector2f(1, -1);
}

void PhysicalGameObject::Update(GameObjectManager* gameObjectManager) {
    std::cout << "Update physical game object" << std::endl;


    //// Check collision with all alive abjects
    //std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
    //for (const GameObject* object : *entitiesAlive) {
    //    // check if try object is collidable
    //    if (object->GetIsCollidable()) {

    //        /*CheckCollideState(object);*/
    //    }
    //}
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

void PhysicalGameObject::CheckCollideState(PhysicalGameObject* object) {

    //bool isRectCollision = CollisionNamespace::CollisionManager::RectCollision(&this, &object);
    
    //// Object finder
    //auto iterator = std::find(_collisionObject.begin(), _collisionObject.end(), object);
    //if (iterator != _collisionObject.end()) {
    //}
    


}

void PhysicalGameObject::OnCollisionEnter() { // Is call when just collide on 

}
void PhysicalGameObject::OnCollisionStay() { // Is call when collide on

}

void PhysicalGameObject::OnCollisionExit() { // Is call when collide was on and pass off

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


