#pragma once

#include "PhysicalGameObject.h"
class CollisionManager;

class Ball : public PhysicalGameObject {
public:
    // Constructor
    Ball();
    Ball(float initialX, float initialY, float radius, std::string name);
    ~Ball();

    void OnCollisionEnter(GameObject* collideObject) override; // Bouncing ball 


private:
    bool _shouldBounce;
};


