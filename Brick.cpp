#include "Brick.h"

Brick::Brick() : GameObject() {
}

Brick::Brick(float initialX, float initialY, float width, float height, std::string name) : GameObject(initialX, initialY, width, height, name)
{
	_isCollidable = true;
}

Brick::~Brick() 
{

}

void Brick::SetHealth(int health) 
{
	_health = health;
}

void Brick::RemoveHealth(int amount) 
{
	_health -= amount;
}

int Brick::GetHealth() const
{
	return _health;
}

sf::FloatRect Brick::GetBoundingBox() const {
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

void Brick::HandleCollision() {
    // Logique de gestion de la collision sp�cifique � Brick
    // Par exemple, ajustez la sant� de la brique ici.
    RemoveHealth(1);
}