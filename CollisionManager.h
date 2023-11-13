#pragma once

class PhysicalGameObject;
class GameObject;
#include <string>
#include <vector>

namespace CollisionNamespace {
    class CollisionManager {
        public:
            CollisionManager();
            ~CollisionManager();

            static void Initialize();

            static bool RectCollision(GameObject* rect1, GameObject* rect2);
            static bool CircleRectCollision(GameObject* circle, GameObject* rect);


            // TOTHINK - Chunk
        private:
    };
}