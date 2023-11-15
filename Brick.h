#pragma once
#include "GameObject.h"

class Brick : public GameObject {
public:
    // Constructor
    Brick();
    Brick(float initialX, float initialY, float width, float height, std::string name, int initialHealth = 3);
    ~Brick();

    /*
        Get / Set
    */
    void SetHealth(int health);
    void RemoveHealth(int amount = 1);
    int GetHealth() const;

private:
    int _health;

    // TO THINK - Brick Color
};