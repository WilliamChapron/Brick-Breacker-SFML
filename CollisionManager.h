#pragma once

#include "Entity.h" 

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    void Initialize();

    void CheckRectCollide(Entity& object, Entity& object2);
    void CheckCircleCollide(Entity& object, Entity& object2);


    // TOTHINK - Chunk

private:
};