#include "GameObject.h"


GameObject::GameObject() 
{
    // Default constructor for GameObject
    Initialize(0.0f, 0.0f, 1, 1, "", nullptr);
}


GameObject::GameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) 
{
    // Rectangle constructor for GameObject
    sf::RectangleShape* newShape = new sf::RectangleShape(sf::Vector2f(sizeW, sizeH));
    Initialize(initialX, initialY, sizeW, sizeH, name, newShape);
}


GameObject::GameObject(float initialX, float initialY, int radius, std::string name) 
{
    // Circle constructor for GameObject
    sf::CircleShape* newShape = new sf::CircleShape(radius);
    Initialize(initialX, initialY, radius * 2, radius * 2, name, newShape);
}

GameObject::~GameObject() 
{
    // Destructor for GameObject
    delete ptr_shape;
}

void GameObject::Initialize(float initialX, float initialY, int sizeW, int sizeH, std::string name, sf::Shape* shape) 
{
    // Initialize method for GameObject
    _position.x = initialX;
    _position.y = initialY;
    _width = sizeW;
    _height = sizeH;
    _name = name;

    shape->setFillColor(sf::Color::Blue);
    shape->setPosition(initialX, initialY);

    ptr_shape = shape;
}

sf::Shape* GameObject::GetShape() 
{
    // Getter for the shape of GameObject
    return ptr_shape;
}

sf::Shape* GameObject::GetShape() const 
{
    // Const getter for the shape of GameObject
    return ptr_shape;
}

void GameObject::Update(GameObjectManager* gameObjectManager) 
{
    // Update method for GameObject
    // Clear object if out of screen bounds
    if (_position.x < 0 || _position.x > RendererManager::_winWidth || _position.y < 0 || _position.y > RendererManager::_winHeight) {
        gameObjectManager->RemoveObject(this);
    }
}

void GameObject::SetPosition(float x, float y) 
{
    // Setter for the position of GameObject
    _position.x = x;
    _position.y = y;
    ptr_shape->setPosition(_position.x, _position.y);
}

sf::Vector2f GameObject::GetPosition() const 
{
    // Getter for the position of GameObject
    return _position;
}

int GameObject::GetWidth() 
{
    // Getter for the width of GameObject
    return _width;
}

int GameObject::GetHeight() 
{
    // Getter for the height of GameObject
    return _height;
}

std::string GameObject::GetName() const
{
    // Getter for the name of GameObject
    return _name;
}

void GameObject::SetSize(int width, int height) 
{
    // Setter for the size of GameObject
    _width = width;
    _height = height;
}

void GameObject::SetScale(float scaleX, float scaleY)
{
    // Setter for the scale of GameObject
    ptr_shape->setScale(scaleX, scaleY);
}

sf::Vector2f GameObject::GetScale() const
{
    // Getter for the scale of GameObject
    return ptr_shape->getScale();
}

void GameObject::SetRotation(float angle) 
{
    // Setter for the rotation of GameObject
    ptr_shape->setRotation(angle);
}

int GameObject::GetRotation() const 
{
    // Getter for the rotation of GameObject
    return ptr_shape->getRotation();
}

bool GameObject::GetHasToCollide() const 
{
    // Getter for the collision flag of GameObject
    return _hasToCollide;
}

bool GameObject::GetIsCollidable() const 
{
    // Getter for the collidable flag of GameObject
    return _isCollidable;
}
