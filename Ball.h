#pragma once
#include "GameObject.h"

class Ball : public GameObject {
public:
    // Constructor
    Ball();
    Ball(float initialX, float initialY, float radius);
    ~Ball();

    void Initialize(float initialX, float initialY, float radius);

private:
    int _radius;
};


