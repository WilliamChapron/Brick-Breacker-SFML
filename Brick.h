#pragma once
#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "CollisionManager.h"

class Brick : public GameObject {
public:
    // Constructor
    Brick();
    Brick(float initialX, float initialY, float width, float height, std::string name);
    ~Brick();


    /*
        Get / Set
    */
    void SetHealth(int health); 
    void RemoveHealth(int amount);
    int GetHealth() const;

    sf::FloatRect GetBoundingBox() const;

    void HandleCollision() override;

private:
    int _health;

    // TO THINK - Brick Color
};