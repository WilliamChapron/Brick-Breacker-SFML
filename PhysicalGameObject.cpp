
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"





PhysicalGameObject::PhysicalGameObject() : GameObject() {
    _moveState = 0;
    _orientation = sf::Vector2f(0, 0);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) : GameObject(initialX, initialY, sizeW, sizeH, name) {
    _orientation = sf::Vector2f(1, 1);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int radius, std::string name) : GameObject(initialX, initialY, radius, name) {
    _orientation = sf::Vector2f(1, 1);
}




void PhysicalGameObject::Move()
{

    _position.x += _speed * _orientation.x * GameNamespace::GameManager::GetDeltaTime();
    _position.y += _speed * _orientation.y * GameNamespace::GameManager::GetDeltaTime();

    //std::cout << "New Position: (" << _position.x << ", " << _position.y << ")" << std::endl;

    //std::cout << _position.x<< std::endl;
    //std::cout << _position.y << std::endl;

    if (ptr_shape != nullptr) {
        ptr_shape->setPosition(_position);
    }
}

void PhysicalGameObject::Update(GameObjectManager* gameObjectManager) {
    //std::cout << "Update physical game object" << std::endl;
    //Move();

    Move();
    
    //std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();

    //for (GameObject* object : *entitiesAlive) {
    //    if (object->GetName() != this->GetName()) {
    //        if (object->GetIsCollidable()) {
    //            PhysicalGameObject* physicalObject = static_cast<PhysicalGameObject*>(object);
    //            // Appeler RectCollision directement comme une fonction statique
    //            bool isRectCollision = CollisionNamespace::CollisionManager::RectCollision(this, physicalObject);
    //            // ...
    //        }
    //    }
    //}
}


void PhysicalGameObject::CheckCollideState(PhysicalGameObject* object) {
    // Utiliser une instance de CollisionManager
    CollisionNamespace::CollisionManager collisionManager;

    bool isRectCollision = collisionManager.RectCollision(this, object);

    auto iterator = std::find(objvect_collisionObject.begin(), objvect_collisionObject.end(), object);

    if (isRectCollision) {
        if (iterator != objvect_collisionObject.end()) {
            OnCollisionStay();
        } else {
            OnCollisionEnter();
            objvect_collisionObject.push_back(object);
        }
    } else {
        if (iterator != objvect_collisionObject.end()) {
            OnCollisionExit();
            objvect_collisionObject.erase(iterator);
        }
    }
}

void PhysicalGameObject::OnCollisionEnter() {
    std::cout << "OnCollisionEnter for object: " << this->GetName() << std::endl;
}

void PhysicalGameObject::OnCollisionStay() {
    std::cout << "OnCollisionStay for object: " << this->GetName() << std::endl;
}

void PhysicalGameObject::OnCollisionExit() {
    std::cout << "OnCollisionExit for object: " << this->GetName() << std::endl;
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