#include "CollisionManager.h"
#include "GameObject.h"
#include "PhysicalGameObject.h"
#include <algorithm>
#include <iostream>


namespace CollisionNamespace {

    CollisionManager::CollisionManager() {
    }

    CollisionManager::~CollisionManager() {
    }

    void CollisionManager::Initialize() {
    }



    bool CollisionManager::RectCollision(GameObject* rect1, GameObject* rect2)
    {
        // Calcul des bords pour les deux objets
        float left1 = rect1->GetPosition().x;
        float right1 = left1 + rect1->GetWidth();
        float top1 = rect1->GetPosition().y;
        float bottom1 = top1 + rect1->GetHeight();

        float left2 = rect2->GetPosition().x;
        float right2 = left2 + rect2->GetWidth();
        float top2 = rect2->GetPosition().y;
        float bottom2 = top2 + rect2->GetHeight();




        // V�rification de la collision sur l'axe des x (horizontal)
        bool collisionX = (left1 < right2) && (right1 > left2);
        // V�rification de la collision sur l'axe des y (vertical)
        bool collisionY = (top1 < bottom2) && (bottom1 > top2);

        // Afficher les r�sultats de collisionX et collisionY
        //std::cout << "CollisionX: " << collisionX << " CollisionY: " << collisionY << std::endl;

        // Retourne true si les deux axes de collision sont vrais
        return collisionX && collisionY;
    }


    bool CollisionManager::CircleRectCollision(GameObject* circle, GameObject* rect) {

        float circleRadius = circle->GetWidth() / 2.f;

        sf::Vector2f circlePosition = circle->GetPosition();

        PhysicalGameObject boundingRect(circlePosition.x, circlePosition.y, 2 * circleRadius, 2 * circleRadius, "Rect");

        sf::Vector2f circleCenter = circlePosition;
        circleCenter.x += circle->GetWidth() / 2.f;
        circleCenter.y += circle->GetHeight() / 2.f;

        sf::Vector2f rectCenter = rect->GetPosition();
        rectCenter.x += rect->GetWidth() / 2.f;
        rectCenter.y += rect->GetHeight() / 2.f;

        bool success = RectCollision(rect, &boundingRect);

        if (success) {
            float fCircleSizeSqr = circleRadius;

            float fRectHalfWidth = rect->GetWidth() / 2.f;
            float fRectHalfHeight = rect->GetHeight() / 2.f;
            float fRectSizeSqr = sqrt((fRectHalfWidth * fRectHalfWidth) + (fRectHalfHeight * fRectHalfHeight));

            float fDistanceMaxSqr = fCircleSizeSqr + fRectSizeSqr;

            float fXDistance = std::abs(circleCenter.x - rectCenter.x);
            float fYDistance = std::abs(circleCenter.y - rectCenter.y);

            float fDistanceSqr = sqrt((fXDistance * fXDistance) + (fYDistance * fYDistance));

            if (fDistanceSqr <= fDistanceMaxSqr)
            {
                //std::cout << "Circle Collision Check: Success! Collision detected." << std::endl;
                return true;
            }
            else {
                //std::cout << "Circle Collision Check: Failed. No collision detected." << std::endl;
            }
        }
        return false;
    }

    int CollisionManager::DetectCollisionFace(GameObject* circle, GameObject* rect2) {
        PhysicalGameObject boundingRect(circle->GetPosition().x, circle->GetPosition().y, 2 * circle->GetWidth(), 2 * circle->GetWidth(), "Rect");

        // Rect of circle
        float left1 = boundingRect.GetPosition().x;
        float right1 = left1 + boundingRect.GetWidth();
        float top1 = boundingRect.GetPosition().y;
        float bottom1 = top1 + boundingRect.GetHeight();

        // Rect of rect
        float left2 = rect2->GetPosition().x;
        float right2 = left2 + rect2->GetWidth();
        float top2 = rect2->GetPosition().y;
        float bottom2 = top2 + rect2->GetHeight();

        float overlapLeft = right1 - left2;
        float overlapRight = right2 - left1;
        float overlapTop = bottom1 - top2;
        float overlapBottom = bottom2 - top1;


        float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });



        if (minOverlap == overlapLeft) {
            //std::cout << "Left " << std::endl;
            return 1;
        }
        else if (minOverlap == overlapRight) {
            //std::cout << "Right " << std::endl;
            return 2;
        }
        else if (minOverlap == overlapTop) {
            //std::cout << "Top " << std::endl;
            return 3;
        }
        else if (minOverlap == overlapBottom) {
            //std::cout << "Bottom " << std::endl;
            return 4;
        }
    }
}

// #TODO Make Chunk between position