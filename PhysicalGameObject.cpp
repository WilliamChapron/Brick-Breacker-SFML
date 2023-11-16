
#include <iostream>

#include <SFML/Graphics.hpp>

#include "PhysicalGameObject.h"





PhysicalGameObject::PhysicalGameObject() : GameObject() {
    _moveState = 0;
    _orientation = sf::Vector2f(0, 0);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) : GameObject(initialX, initialY, sizeW, sizeH, name) {
    _orientation = sf::Vector2f(-1, 1);
}


PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int radius, std::string name) : GameObject(initialX, initialY, radius, name) {
    _orientation = sf::Vector2f(-1, 1);
}




void PhysicalGameObject::Move()
{

    _position.x += _speed * _orientation.x * GameNamespace::GameManager::GetDeltaTime();
    _position.y += _speed * _orientation.y * GameNamespace::GameManager::GetDeltaTime();


    if (ptr_shape != nullptr) {
        ptr_shape->setPosition(_position);
    }
}

void PhysicalGameObject::Update(GameObjectManager* gameObjectManager) {


    // Clear object out screen
    if (_position.x < 0 || _position.x > RendererManager::_winWidth || _position.y < 0 || _position.y > RendererManager::_winHeight) {
        gameObjectManager->RemoveObject(this);
    }

    Move();

    // Not try to collide if not collider object
    if (!this->GetHasToCollide()) {
        return;
    }

    // Check collision with all alive abjects
    std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
    for (GameObject* object : *entitiesAlive) {
        // check if try object is collidable
        if (object->GetName() != this->GetName()) {
            if (object->GetIsCollidable()) {
                PhysicalGameObject* physicalObject = static_cast<PhysicalGameObject*>(object);
                CheckCollideState(physicalObject); // Start event from collision
            }

        }

    }
}


void PhysicalGameObject::CheckCollideState(PhysicalGameObject* object) {

    bool isCollision = CollisionNamespace::CollisionManager::CircleRectCollision(this, object);




    // Event collision Logic 

    // Object finder
    auto iterator = std::find(objvect_collisionObject.begin(), objvect_collisionObject.end(), object);

    // Collide
    if (isCollision) {
        // Object Already collide
        if (iterator != objvect_collisionObject.end()) {
            //std::cout << "OnCollisionStay" << std::endl;
            OnCollisionStay();
        }
        // Object Begin Collide
        else {
            std::cout << "OnCollisionEnter" << std::endl;
            std::cout << "--" << std::endl;
            OnCollisionEnter(object);
            objvect_collisionObject.push_back(object);
        }
    }
    // No Collide
    else {
        // Object Exit Collide
        if (iterator != objvect_collisionObject.end()) {
            //std::cout << "OnCollisionExit" << std::endl;
            objvect_collisionObject.erase(iterator);
            OnCollisionExit();

        }
        // Object Not collide
    }
}

void PhysicalGameObject::CollisionUpdate() {

}

void PhysicalGameObject::OnCollisionEnter(GameObject* collideObject) // Is call when just collide on 
{

}
void PhysicalGameObject::OnCollisionStay() // Is call when collide on
{

}

void PhysicalGameObject::OnCollisionExit() // Is call when collide was on and pass off
{

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

