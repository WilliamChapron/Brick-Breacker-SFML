#include "PhysicalGameObject.h"

#include <iostream>
#include <SFML/Graphics.hpp>


PhysicalGameObject::PhysicalGameObject() : GameObject() 
{
    _moveState = 0;
    _orientation = sf::Vector2f(0, 0);
}

PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) : GameObject(initialX, initialY, sizeW, sizeH, name) 
{
    _orientation = sf::Vector2f(0, 0);
}

PhysicalGameObject::PhysicalGameObject(float initialX, float initialY, int radius, std::string name) : GameObject(initialX, initialY, radius, name) 
{
    _orientation = sf::Vector2f(0, 0);
}

void PhysicalGameObject::Move() 
{
    // Calculate the vector's magnitude
    float magnitude = std::sqrt(_orientation.x * _orientation.x + _orientation.y * _orientation.y);

    // Normalize the orientation vector
    if (magnitude != 0) 
    {
        _orientation.x /= magnitude;
        _orientation.y /= magnitude;
    }

    // Update the position based on orientation, speed, and delta time
    _position.x += _speed * _orientation.x * GameNamespace::GameManager::GetDeltaTime();
    _position.y += _speed * _orientation.y * GameNamespace::GameManager::GetDeltaTime();

    // Update the shape's position if available
    if (ptr_shape != nullptr) 
    {
        ptr_shape->setPosition(_position);
    }
}

void PhysicalGameObject::Update(GameObjectManager* gameObjectManager)
{
    // Remove object if out of screen bounds
    if (_position.x < 0 || _position.x > RendererManager::_winWidth || _position.y < 0 || _position.y > RendererManager::_winHeight) 
    {
        gameObjectManager->RemoveObject(this);
        return;
    }

    Move();

    // Skip collision check if the object is not a collider
    if (!this->GetHasToCollide()) 
    {
        return;
    }

    // Check collision with all alive objects
    std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
    for (GameObject* object : *entitiesAlive) 
    {
        // Check if the current object is collidable
        if (object->GetName() != this->GetName()) 
        {
            if (object->GetIsCollidable()) 
            {
                PhysicalGameObject* physicalObject = static_cast<PhysicalGameObject*>(object);
                CheckCollideState(physicalObject); // Start event from collision
            }
        }
    }
}

void PhysicalGameObject::CheckCollideState(PhysicalGameObject* object) 
{
    // Check for collision using Circle-Rectangle collision detection
    bool isCollision = CollisionNamespace::CollisionManager::CircleRectCollision(this, object);

    // Object finder
    auto iterator = std::find(objvect_collisionObject.begin(), objvect_collisionObject.end(), object);

    if (isCollision) 
    {
        // Object already collided
        if (iterator != objvect_collisionObject.end()) 
        {
            OnCollisionStay();
        }
        // Object begins to collide
        else 
        {
            OnCollisionEnter(object);
            objvect_collisionObject.push_back(object);
        }
    }
    // No collision
    else {
        // Object stops colliding
        if (iterator != objvect_collisionObject.end()) {
            objvect_collisionObject.erase(iterator);
            OnCollisionExit();
        }
        // Object not colliding
    }
}

void PhysicalGameObject::CollisionUpdate() {

}

void PhysicalGameObject::OnCollisionEnter(GameObject* collideObject) 
{
    // Event called when collision begins
}

void PhysicalGameObject::OnCollisionStay() 
{
    // Event called when collision continues
}

void PhysicalGameObject::OnCollisionExit() 
{
    // Event called when collision ends
}

sf::Vector2f PhysicalGameObject::GetOrientation() const
{
    return _orientation;
}

int PhysicalGameObject::GetSpeed() const
{
    return _speed;
}

void PhysicalGameObject::SetOrientation(float x, float y)
{
    _orientation.x = x;
    _orientation.y = y;
}

void PhysicalGameObject::SetSpeed(int speed) 
{
    _speed = speed;
}
