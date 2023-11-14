#include "CollisionManager.h"
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

         //Afficher les résultats de collisionX et collisionY
        //std::cout << "CollisionX: " << collisionX << " CollisionY: " << collisionY << std::endl;

        // Retourne true si les deux axes de collision sont vrais
        return collisionX && collisionY;
    }

    //#TODO - Utiliser le game object plutot que la shape 
    bool CollisionManager::CircleRectCollision(GameObject& circle, GameObject& rect) {
        //sf::Shape* rectShape_ref = rect.GetShape();
        //sf::Shape* circleShape_ref = circle.GetShape();

        //sf::CircleShape* circleShape = static_cast<sf::CircleShape*>(circleShape_ref);
        //sf::RectangleShape* rectShape = static_cast<sf::RectangleShape*>(rectShape_ref);

        // Circle Informations
        float circleRadius = circle.GetWidth();
        std::cout << "Circle Radius: " << circleRadius << std::endl;

        // Center Position
        sf::Vector2f circlePosition = circle.GetPosition();
        std::cout << "Circle Position: (" << circlePosition.x << ", " << circlePosition.y << ")" << std::endl;

        // Rectangle Position
        sf::Vector2f rectPosition = rect.GetPosition();
        std::cout << "Rectangle Position: (" << rectPosition.x << ", " << rectPosition.y << ")" << std::endl;

        // Closest x/y
        //float closestX = std::max(rectPosition.x, std::min(circlePosition.x, rectPosition.x + rect.GetWidth()));
        //float closestY = std::max(rectPosition.y, std::min(circlePosition.y, rectPosition.y + rect.GetHeight()));
        //std::cout << "Closest X: " << closestX << " Closest Y: " << closestY << std::endl;

        //// Distance between closest x/y and circle center // REAL DISTANCE TAKE CARE OF RECT SIZE WITH CLOSEST 
        //float distance = std::sqrt((circlePosition.x - closestX) * (circlePosition.x - closestX) + (circlePosition.y - closestY) * (circlePosition.y - closestY));
        //std::cout << "Distance: " << distance << std::endl;


        float deltaX = circlePosition.x - std::max(rectPosition.x, std::min(circlePosition.x, rectPosition.x + rect.GetWidth()));
        float deltaY = circlePosition.y - std::max(rectPosition.y, std::min(circlePosition.y, rectPosition.y + rect.GetHeight()));

        float deltaXSquared = deltaX * deltaX;
        float deltaYSquared = deltaY * deltaY;
        float circleRadiusSquared = circleRadius * circleRadius;

        bool collisionX = deltaXSquared <= circleRadiusSquared;
        bool collisionY = deltaYSquared <= circleRadiusSquared;

        bool collision = collisionX && collisionY;


        /*if (distance <= circleRadius) {
            std::cout << "Distance inferieur au circle radius: " << distance << std::endl;
        }
        if (distance >= circleRadius) {
            std::cout << "Distance superieur au circle radius: " << distance << std::endl;
        }

        return distance <= circleRadius;*/
        return collision;
    }



    bool AreRectanglesColliding(const sf::FloatRect& rect1, const sf::FloatRect& rect2) {
        return rect1.intersects(rect2);
    }

    CollisionFace CollisionManager::DetectCollisionFace(const sf::FloatRect& rect1, const sf::FloatRect& rect2) {
        // Utilisez la fonction fournie pour détecter la face de collision
        if (!AreRectanglesColliding(rect1, rect2)) {
            return CollisionFace::None;
        }

        float overlapLeft = rect2.left + rect2.width - rect1.left;
        float overlapRight = rect1.left + rect1.width - rect2.left;
        float overlapTop = rect2.top + rect2.height - rect1.top;
        float overlapBottom = rect1.top + rect1.height - rect2.top;

        float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

        if (minOverlap == overlapLeft) {
            return CollisionFace::Left;
        }
        else if (minOverlap == overlapRight) {
            return CollisionFace::Right;
        }
        else if (minOverlap == overlapTop) {
            return CollisionFace::Top;
        }
        else {
            return CollisionFace::Bottom;
        }
    }





}

