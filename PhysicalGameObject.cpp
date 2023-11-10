
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
    

    //// Check collision with all alive abjects
    //std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
    //for (GameObject* object : *entitiesAlive) {
    //    // check if try object is collidable
    //    if (object->GetName() != this->GetName()) {
    //        if (object->GetIsCollidable()) {
    //            /*std::cout << object->GetName() << std::endl;*/
    //            PhysicalGameObject* physicalObject = static_cast<PhysicalGameObject*>(object);
    //            CheckCollideState(physicalObject);
    //        }
    //    }

    //}
}


void PhysicalGameObject::CheckCollideState(PhysicalGameObject* object) {

    bool isRectCollision = CollisionNamespace::CollisionManager::RectCollision(this, object);

    //std::cout << isRectCollision << "" << object->GetName() << std::endl;

    // Object finder
    auto iterator = std::find(objvect_collisionObject.begin(), objvect_collisionObject.end(), object);

    // Collide
    if (isRectCollision) {
        // Object Already collide
        if (iterator != objvect_collisionObject.end()) {
            //std::cout << "OnCollisionStay" << std::endl;
            OnCollisionStay();
        }
        // Object Begin Collide
        else {
            std::cout << "OnCollisionEnter" << std::endl;
            OnCollisionEnter();
            objvect_collisionObject.push_back(object);
        }
    }
    // No Collide
    else {
        // Object Exit Collide
        if (iterator != objvect_collisionObject.end()) {
            std::cout << "OnCollisionExit" << std::endl;
            OnCollisionExit();
            objvect_collisionObject.erase(iterator);
        }
        // Object Not collide
    }
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


