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

    bool Contains(const sf::Vector2f& point) const;

    void Move(const sf::Vector2f& offset);

    sf::FloatRect GetBoundingBox() const;

private:
    int _health;

    // TO THINK - Brick Color
};