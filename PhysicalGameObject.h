#pragma once

#include "GameObject.h" 
#include <SFML/Graphics.hpp>
#include "GameManager.h"

class PhysicalGameObject : public GameObject {
public:
    // Constructor
    PhysicalGameObject();
    PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name);
    PhysicalGameObject(float initialX, float initialY, int radius, std::string name);

    // Logic
    void Move();
    virtual void CollisionOnEnter();
    virtual void CollisionOnExit();

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
    int _moveState;
    int _speed; 
    sf::Vector2f _orientation;
};
