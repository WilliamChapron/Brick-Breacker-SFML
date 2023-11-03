#pragma once
#include "GameObject.h"

class Paddle : public GameObject {
public:
    Paddle();
    Paddle(float initialX, float initialY, float width, float height);

    void Initialize(float initialX, float initialY, float width, float height);

    // $ Move the paddle left or right
    void Move(float deltaX);

    void SetWidth(float width);
    float GetWidth() const;

    void CheckCollision() override;

private:
    float width;
    float height;

};