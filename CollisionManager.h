#pragma once

#include "PhysicalGameObject.h" 

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    void Initialize();

    void RectCollision(PhysicalGameObject& object, PhysicalGameObject& object2);
    bool CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect);


    // TOTHINK - Chunk

private:
};