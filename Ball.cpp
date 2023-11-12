#include "Ball.h"

Ball::Ball() : PhysicalGameObject() {
    // Configuration suppl�mentaire si n�cessaire
}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name) {
    // Configuration suppl�mentaire sp�cifique � la classe Ball
    _speed = 100;
    _moveState = 1;
    _isCollidable = true;

    sf::Vector2f setorigin(radius / 2.f, radius / 2.f);
    this->GetShape()->setOrigin(setorigin);
}

Ball::~Ball() {
    // Nettoyage suppl�mentaire si n�cessaire
}

sf::FloatRect Ball::GetBoundingBox() const {
    // En supposant que votre balle est repr�sent�e comme un cercle
    sf::Vector2f position = GetPosition();

    // Assurez-vous de convertir la forme en sf::CircleShape pour acc�der � getRadius
    sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(GetShape());

    if (circleShape) {
        float radius = circleShape->getRadius();
        // Calculez la bo�te englobante en fonction de la position et du rayon
        return sf::FloatRect(position.x - radius, position.y - radius, 2 * radius, 2 * radius);
    }
    else {
        // G�rez le cas o� la forme n'est pas un cercle
        // Vous voudrez peut-�tre renvoyer une bo�te englobante par d�faut dans ce cas
        return sf::FloatRect(position.x, position.y, 0, 0);
    }
}

void Ball::HandleCollision(CollisionFace face) {
    // Logique de gestion de la collision sp�cifique � la balle
    // Par exemple, ajustez la position ou la v�locit� de la balle ici.
}
