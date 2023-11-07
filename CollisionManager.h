#pragma once

#include "PhysicalGameObject.h" 

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    void Initialize();

    bool RectCollision(PhysicalGameObject& rect1, PhysicalGameObject& rect2);
    bool CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect);


    // TOTHINK - Chunk

private:
};