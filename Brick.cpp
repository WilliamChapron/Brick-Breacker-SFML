#include "Brick.h"
#include "GameObject.h"


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

bool Brick::Contains(const sf::Vector2f& point) const {
    // Utilisez la fonction GetPosition() de la classe de base GameObject
    return (point.x >= GetPosition().x && point.x <= GetPosition().x + GetWidth() &&
        point.y >= GetPosition().y && point.y <= GetPosition().y + GetHeight());
}

void Brick::Move(const sf::Vector2f& offset) {
    // Utilisez la fonction SetPosition() de la classe de base GameObject
    SetPosition(GetPosition().x + offset.x, GetPosition().y + offset.y);
}

sf::FloatRect Brick::GetBoundingBox() const {
    // Utilisez les coordonnées et dimensions de la brique pour créer un sf::FloatRect
    return sf::FloatRect(_position.x, _position.y, _width, _height);
}
