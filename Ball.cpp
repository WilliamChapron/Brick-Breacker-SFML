#include "Ball.h"

Ball::Ball() : PhysicalGameObject() {
    // Configuration supplémentaire si nécessaire
}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name) {
    // Configuration supplémentaire spécifique à la classe Ball
    _speed = 100;
    _moveState = 1;
    _isCollidable = true;

    sf::Vector2f setorigin(radius / 2.f, radius / 2.f);
    this->GetShape()->setOrigin(setorigin);
}

Ball::~Ball() {
    // Nettoyage supplémentaire si nécessaire
}

sf::FloatRect Ball::GetBoundingBox() const {
    // En supposant que votre balle est représentée comme un cercle
    sf::Vector2f position = GetPosition();

    // Assurez-vous de convertir la forme en sf::CircleShape pour accéder à getRadius
    sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(GetShape());

    if (circleShape) {
        float radius = circleShape->getRadius();
        // Calculez la boîte englobante en fonction de la position et du rayon
        return sf::FloatRect(position.x - radius, position.y - radius, 2 * radius, 2 * radius);
    }
    else {
        // Gérez le cas où la forme n'est pas un cercle
        // Vous voudrez peut-être renvoyer une boîte englobante par défaut dans ce cas
        return sf::FloatRect(position.x, position.y, 0, 0);
    }
}

void Ball::HandleCollision(CollisionFace face) {
    // Logique de gestion de la collision spécifique à la balle
    // Par exemple, ajustez la position ou la vélocité de la balle ici.
}
