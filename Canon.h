#pragma once

#include "PhysicalGameObject.h"

class Ball;
class GameObjectManager;

class Canon : public PhysicalGameObject {
public:
    // Constructor
    Canon();
    Canon(float initialX, float initialY, float width, float height, std::string name);

    // Destructor
    ~Canon();
    void RotateTowardsMouse(sf::Vector2i mousePosition);
    void Shoot(sf::Vector2f targetPosition, GameObjectManager* gameObjectManager);

private:

};

// TO-THINK - Canon control is not only orientation inverse but also specific control de