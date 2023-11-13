#pragma once

#include "PhysicalGameObject.h" 
#include <string>
#include <vector>

namespace CollisionNamespace {

    enum class CollisionFace {
        None,
        Left,
        Right,
        Top,
        Bottom
    };

    class CollisionManager {
    public:
        CollisionManager();
        ~CollisionManager();

        void Initialize();
        static bool RectCollision(GameObject* rect1, GameObject* rect2);
        static bool CircleRectCollision(GameObject& circle, GameObject& rect);
        static CollisionFace DetectCollisionFace(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
    };
}
