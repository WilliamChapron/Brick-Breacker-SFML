#include "Brick.h"
#include "GameObjectManager.h"

Brick::Brick() : GameObject(), _health(3) {
}

Brick::Brick(float initialX, float initialY, float width, float height, std::string name, int initialHealth)
    : GameObject(initialX, initialY, width, height, name), _health(initialHealth) {
    _hasToCollide = false;
    _isCollidable = true;
}

Brick::~Brick() {
}

void Brick::Update(GameObjectManager* gameObjectManager) {

    if (_health <= 0) {
        gameObjectManager->RemoveObject(this);
    }
}

void Brick::SetHealth(int health) {
    _health = health;
}

void Brick::RemoveHealth(int amount) {
    _health -= amount;

    //check if the brick is destroyed
    
}

int Brick::GetHealth() const {
    return _health;
}
