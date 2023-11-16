#include "Canon.h"
#include <iostream>

Canon::Canon() : PhysicalGameObject() 
{
    // Default constructor for Canon, inheriting from PhysicalGameObject
}

Canon::Canon(float initialX, float initialY, float width, float height, std::string name) : PhysicalGameObject(initialX, initialY, width, height, name) 
{
    // Constructor for Canon with specified parameters, inheriting from PhysicalGameObject
    _hasToCollide = false;
    _isCollidable = false;
    aliveBallLimit = 2;

    // Set the origin of the shape to the center
    sf::Vector2f origin = this->GetShape()->getOrigin();
    sf::Vector2f setOrigin(width / 2.f, height / 2.f);
    this->GetShape()->setOrigin(setOrigin);
}

Canon::~Canon() 
{
    // Destructor for Canon
}

void Canon::RotateTowardsMouse(sf::Vector2i mousePosition) 
{
    // Rotate the canon towards the mouse position

    sf::Vector2f canonPosition = this->GetPosition();
    sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    sf::Vector2f directionVector = mousePositionFloat - canonPosition;
    float angle = atan2(directionVector.y, directionVector.x) * 180 / 3.14159;

    if (angle >= -160 && angle <= -20) 
    {
        this->SetRotation(angle);
    }
}

void Canon::Shoot(sf::Vector2f targetPosition, GameObjectManager* gameObjectManager) 
{
    // Shoot a ball from the canon towards the target position

    if (gameObjectManager->FindObjectsByName("Ball")->size() <= aliveBallLimit) 
    {
        sf::Vector2f canonPosition = this->GetPosition();
        sf::Vector2f direction = targetPosition - canonPosition;
        float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (targetPosition.y <= canonPosition.y - this->GetHeight()) 
        {
            // Normalize the direction vector
            direction.x /= magnitude;
            direction.y /= magnitude;
            // Create a new Ball object and add it to the GameObjectManager
            Ball* objectBall = new Ball(canonPosition.x - 8, canonPosition.y, 8, "Ball");
            objectBall->SetOrientation(direction.x, direction.y);
            gameObjectManager->AddObject(objectBall);
            // Increment the ball used count
            GameNamespace::GameManager::_ballUsed += 1;
            std::cout << "ball used " << GameNamespace::GameManager::_ballUsed << std::endl;
        }
    }
}
