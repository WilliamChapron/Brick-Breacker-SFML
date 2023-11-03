#pragma once
#include "GameObject.h"

class Brick : public GameObject {
public:
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
    int health;
    float width;
    float height;

    // TO THINK - Brick Color
};