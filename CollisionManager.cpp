#include "CollisionManager.h"

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::Initialize() {
}

void CollisionManager::RectCollision(PhysicalGameObject& object, PhysicalGameObject& object2) {
}



//bool CollisionManager::CircleRectCollision(PhysicalGameObject& circle, PhysicalGameObject& rect) {
//    // Obtenez le centre du cercle
//    sf::RectangleShape rectShape_ref = dynamic_cast<sf::RectangleShape&>(*rect.GetShape());
//    sf::CircleShape circleShape_ref = dynamic_cast<sf::CircleShape&>(*circle.GetShape());
//
//    // Circle Informations
//    float circleRadius = circleShape_ref.getRadius();
//
//    // Center Position
//    sf::Vector2f circlePosition = circleShape_ref.getPosition();
//    // Rectangle Position
//    sf::Vector2f rectanglePosition = rectShape_ref.getPosition();
//
//    // 
//    float closestX = std::max(rectanglePosition.x, std::min(circlePosition.x, rectanglePosition.x + rectShape_ref.getSize().x));
//    float closestY = std::max(rectanglePosition.y, std::min(circlePosition.y, rectanglePosition.y + rectShape_ref.getSize().y));
//
//    // 
//    float distance = std::sqrt((circlePosition.x - closestX) * (circlePosition.x - closestX) + (circlePosition.y - closestY) * (circlePosition.y - closestY));
//
//    // Vérifiez s'il y a collision
//    return distance <= circleRadius;
//}