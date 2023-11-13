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




        // Vérification de la collision sur l'axe des x (horizontal)
        bool collisionX = (left1 < right2) && (right1 > left2);
        // Vérification de la collision sur l'axe des y (vertical)
        bool collisionY = (top1 < bottom2) && (bottom1 > top2);

        // Afficher les résultats de collisionX et collisionY
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

        //std::cout << rectCenter.x << ";" << rectCenter.y << std::endl;

        // Check rect collide before check circle collide
        bool success = RectCollision(rect, &boundingRect);

        if (success) {

            //std::cout << "AABB Collides" << std::endl;

            float fCircleSizeSqr = circleRadius;

            float fRectHalfWidth = rect->GetWidth() / 2.f;
            float fRectHalfHeight = rect->GetWidth() / 2.f;
            float fRectSizeSqr = sqrt((fRectHalfWidth * fRectHalfWidth) + (fRectHalfHeight * fRectHalfHeight));

            float fDistanceMaxSqr = fCircleSizeSqr + fRectSizeSqr;

            //std::cout << "Rect Collision Check: Success!" << std::endl;

            float fXDistance = std::abs(circleCenter.x - rectCenter.x);
            float fYDistance = std::abs(circleCenter.y - rectCenter.y);

            float fDistanceSqr = sqrt((fXDistance * fXDistance) + (fYDistance * fYDistance));

            //std::cout << "Distance Max: " << fDistanceMaxSqr << "| Distance: " << fDistanceSqr << std::endl;

            //sf::Vector2f circleRectDistance = sf::Vector2f(, std::abs(circleCenter.y - rectCenter.y));
            //std::cout << circleRectDistance.x << std::endl;
            //std::cout << circleRectDistance.y << std::endl;
            //std::cout << "Circle-Rectangle Distance: (" << circleRectDistance.x << ", " << circleRectDistance.y << ")" << std::endl;

            //sf::Vector2f maxRectDistance = sf::Vector2f(std::abs((rectPos.x + rect->GetWidth()) - rectCenter.x), std::abs((rectPos.y + rect->GetHeight()) - rectCenter.y));
           // sf::Vector2f maxRectDistance = sf::Vector2f(rect->GetWidth()/2, rect->GetHeight() / 2);
            //std::cout << "Max Rectangle Distance: (" << maxRectDistance.x << ", " << maxRectDistance.y << ")" << std::endl;

            // Vérification pour l'axe x
            //bool collisionX = maxRectDistance.x + circleRadius >= circleRectDistance.x;
            //std::cout << maxRectDistance.x + circleRadius << std::endl;
            //std::cout << circleRectDistance.x << std::endl;

            // Vérification pour l'axe y
           // bool collisionY = maxRectDistance.y + circleRadius >= circleRectDistance.y;
            //std::cout << maxRectDistance.y + circleRadius << std::endl;
            //std::cout << circleRectDistance.y << std::endl;


            //std::cout << circleRectDistance.y << std::endl;

            //std::cout << "Circle Collision Check (X-axis): " << (collisionX ? "Success! Collision detected." : "Failed. No collision detected.") << std::endl;
            //std::cout << "Circle Collision Check (Y-axis): " << (collisionY ? "Success! Collision detected." : "Failed. No collision detected.") << std::endl;

             //Vérification globale
            //if (collisionX && collisionY) {
            if(fDistanceSqr <= fDistanceMaxSqr)
            {
                std::cout << "Circle Collision Check: Success! Collision detected." << std::endl;
                return true;
            }
            else {
                //std::cout << "Circle Collision Check: Failed. No collision detected." << std::endl;
            }
        }
        return false;
    }



    //void CollisionManager::HandleCollision(GameObject* object1, GameObject* object2)
    //{
    //    if (CheckCollision(object1, object2))
    //    {
    //        std::cout << "Success" << std::endl;
    //
    //        // Rebondissement en fonction de l'orientation de l'objet
    //        float object1Speed = object1->GetSpeed();
    //        sf::Vector2f object1Orientation = object1->GetOrientation();
    //
    //        // Inversion de l'orientation sur l'axe x ou y en fonction de l'orientation actuelle
    //        if (object1Orientation.x != 0) {
    //            object1->SetOrientation(-object1Orientation.x, object1Orientation.y);
    //        }
    //        if (object1Orientation.y != 0) {
    //            object1->SetOrientation(object1Orientation.x, -object1Orientation.y);
    //        }
    //    }
    //}
}