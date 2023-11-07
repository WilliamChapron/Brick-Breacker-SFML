#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::Initialize() {
}



bool CollisionManager::RectCollision(PhysicalGameObject& rect1, PhysicalGameObject& rect2)
{
    // Calcul des bords pour les deux objets
    float left1 = rect1.GetPosition().x;
    float right1 = left1 + rect1.GetWidth();
    float top1 = rect1.GetPosition().y;
    float bottom1 = top1 + rect1.GetHeight();

    float left2 = rect2.GetPosition().x;
    float right2 = left2 + rect2.GetWidth();
    float top2 = rect2.GetPosition().y;
    float bottom2 = top2 + rect2.GetHeight();




    // Vérification de la collision sur l'axe des x (horizontal)
    bool collisionX = (left1 < right2) && (right1 > left2);
    // Vérification de la collision sur l'axe des y (vertical)
    bool collisionY = (top1 < bottom2) && (bottom1 > top2);

    // Afficher les résultats de collisionX et collisionY
    //std::cout << "CollisionX: " << collisionX << " CollisionY: " << collisionY << std::endl;

    // Retourne true si les deux axes de collision sont vrais
    return collisionX && collisionY;
}

 //#TODO - Utiliser le game object plutot que la shape 
bool CollisionManager::CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect) {
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