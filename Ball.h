#pragma once

#include "PhysicalGameObject.h"
#include "CollisionManager.h"

class Ball : public PhysicalGameObject {
public:
    // Constructors
    Ball();
    Ball(float initialX, float initialY, float radius, std::string name);

    // Destructor
    ~Ball();


private:
};