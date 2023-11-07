#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::Initialize() {
}

void CollisionManager::RectCollision(PhysicalGameObject& object, PhysicalGameObject& object2) {
}


// #TODO - Utiliser le game object plutot que la shape 
bool CollisionManager::CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect) {
    // Obtenez le centre du cercle
    sf::Shape* rectShape_ref = rect.GetShape();
    sf::Shape* circleShape_ref = circle.GetShape();

    sf::CircleShape* circleShape = static_cast<sf::CircleShape*>(circleShape_ref);
    sf::RectangleShape* rectShape = static_cast<sf::RectangleShape*>(rectShape_ref);

    // Circle Informations
    float circleRadius = circleShape->getRadius();
    /*std::cout << circleRadius << std::endl;*/

    // Center Position
    sf::Vector2f circlePosition = circleShape->getPosition();
    // Rectangle Position
    sf::Vector2f rectPosition = rectShape->getPosition();

    // Closest x/y
    float closestX = std::max(rectPosition.x, std::min(circlePosition.x, rectPosition.x + rectShape->getSize().x));
    float closestY = std::max(rectPosition.y, std::min(circlePosition.y, rectPosition.y + rectShape->getSize().y));

    // DIstance between closest x/y and circle center
    float distance = std::sqrt((circlePosition.x - closestX) * (circlePosition.x - closestX) + (circlePosition.y - closestY) * (circlePosition.y - closestY));

    return distance <= circleRadius;
}