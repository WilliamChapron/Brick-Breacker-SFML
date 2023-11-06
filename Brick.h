#pragma once
#include "GameObject.h"

class Brick : public GameObject {
public:
    // Constructor
    Brick();
    Brick(float initialX, float initialY, float width, float height);

    void Initialize(float initialX, float initialY, float width, float height);

    /*
        Get / Set
    */
    void SetHealth(int health); 
    void RemoveHealth(int amount);
    int GetHealth() const;

private:
    int _health;
    float _width;
    float _height;

    // TO THINK - Brick Color
};