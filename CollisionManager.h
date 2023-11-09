#pragma once

#include "PhysicalGameObject.h" 

namespace CollisionNamespace {
    class CollisionManager {
        public:
            CollisionManager();
            ~CollisionManager();

            static void Initialize();

            static bool RectCollision(PhysicalGameObject& rect1, PhysicalGameObject& rect2);
            static bool CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect);


            // TOTHINK - Chunk
        private:
    };
}