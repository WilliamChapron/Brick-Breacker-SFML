#include "Brick.h"

Brick::Brick() : GameObject() {
}

Brick::Brick(float initialX, float initialY, float width, float height, std::string name) : GameObject(initialX, initialY, width, height, name)
{
	_hasToCollide = false;
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