#include "Brick.h"
#include "GameObjectManager.h"
#include "GameManager.h"

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
        int calculScore = GameNamespace::GameManager::_score + 100 / GameNamespace::GameManager::_ballUsed;
        GameNamespace::GameManager::_score = calculScore;
        std::cout << "score" << GameNamespace::GameManager::_score << std::endl;
    }
    if (_health == 1) {
        ptr_shape->setFillColor(sf::Color::Red);
    }
    if (_health == 2) {
        ptr_shape->setFillColor(sf::Color::Yellow);
    }
    if (_health == 3) {
        ptr_shape->setFillColor(sf::Color::Green);
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
