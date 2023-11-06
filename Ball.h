#pragma once

#include "PhysicalGameObject.h"

class Ball : public PhysicalGameObject {
public:
    // Constructor
    Ball();
    Ball(float initialX, float initialY, float radius);
    ~Ball();

private:
};


