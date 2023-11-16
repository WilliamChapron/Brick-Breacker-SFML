#include "Brick.h"

Brick::Brick() : GameObject(), _health(3) 
{
    // Default constructor for Brick, inheriting from GameObject, with default health value
}

Brick::Brick(float initialX, float initialY, float width, float height, std::string name, int initialHealth)
    : GameObject(initialX, initialY, width, height, name), _health(initialHealth) 
{
    // Constructor for Brick with specified parameters, inheriting from GameObject, and custom initial health
    _hasToCollide = false;
    _isCollidable = true;
}

Brick::~Brick() 
{
    // Destructor for Brick
}

void Brick::Update(GameObjectManager* gameObjectManager) 
{
    // Update method for Brick, including health-based color changes and removal if health reaches zero

    if (_health <= 0) 
    {
        // Remove the Brick from the GameObjectManager and update the score
        gameObjectManager->RemoveObject(this);
        int calculatedScore = GameNamespace::GameManager::_score + 100 / GameNamespace::GameManager::_ballUsed;
        GameNamespace::GameManager::_score = calculatedScore;
        std::cout << "score" << GameNamespace::GameManager::_score << std::endl;
    }
    if (_health == 1) 
    {
        ptr_shape->setFillColor(sf::Color::Red);
    }
    if (_health == 2) 
    {
        ptr_shape->setFillColor(sf::Color::Yellow);
    }
    if (_health == 3) 
    {
        ptr_shape->setFillColor(sf::Color::Green);
    }
}

void Brick::SetHealth(int health) 
{
    // Setter for the health of the Brick
    _health = health;
}

void Brick::RemoveHealth(int amount) 
{
    // Remove health from the Brick
    _health -= amount;

    // Check if the Brick is destroyed (health reaches zero or below)
}

int Brick::GetHealth() const 
{
    // Getter for the health of the Brick
    return _health;
}
