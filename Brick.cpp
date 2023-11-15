#include "Brick.h"

Brick::Brick() : GameObject(), _health(3) {
}

Brick::Brick(float initialX, float initialY, float width, float height, std::string name, int initialHealth)
    : GameObject(initialX, initialY, width, height, name), _health(initialHealth) {
    _hasToCollide = false;
    _isCollidable = true;
}

Brick::~Brick() {
}

void Brick::SetHealth(int health) {
    _health = health;
}

void Brick::RemoveHealth(int amount) {
    _health -= amount;

    // Check if the brick is destroyed
    if (_health <= 0) {
        _hasToCollide = false;
        _isCollidable = false;
    }
}

int Brick::GetHealth() const {
    return _health;
}
