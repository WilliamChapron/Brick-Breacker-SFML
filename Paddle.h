#pragma once
#include "GameObject.h"
#include "PhysicalGameObject.h"

class Paddle : public GameObject {
public:
    // Constructor
    Paddle();
    Paddle(float initialX, float initialY, float width, float height);
    ~Paddle();

    void Initialize(float initialX, float initialY, float width, float height);

    // $ Move the paddle left or right
    void Move(float deltaX);

    void SetWidth(float width);
    float GetWidth() const;

    //void CheckRectCollide(Entity& object, Entity& object2); override;

private:

};

// TO-THINK - Paddle control is not only orientation inverse but also specific control depends on paddle rebond pos