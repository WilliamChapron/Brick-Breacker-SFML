#pragma once

#include "GameObject.h" 
#include <SFML/Graphics.hpp>

class PhysicalGameObject : public GameObject {
public:
    // Constructor
    PhysicalGameObject();
    PhysicalGameObject(float initialX, float initialY);

    void Initialize(float initialX, float initialY, int sizeW, int sizeH) override;

    void Move(float dx, float dy);

    /*
        Get
    */
    sf::Vector2f GetOrientation() const;
    int GetSpeed() const;

    /*
        Set
    */
    void SetOrientation(float x, float y);
    void SetSpeed(int speed);


protected:
    int _speed; 
    sf::Vector2f _orientation;
};
