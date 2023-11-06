#pragma once

#include "GameObject.h" 
#include <SFML/Graphics.hpp>

class Entity : public GameObject {
public:
    Entity();
    Entity(float initialX, float initialY);

    void Initialize(float initialX, float initialY) override;

    void Move(float dx, float dy);

    sf::Vector2f GetVelocity() const;

protected:
    sf::Vector2f _velocity; 
    sf::Vector2f _orientation;

};
