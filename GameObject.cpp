#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject() {
    Initialize(0.0f, 0.0f, 1, 1, "", nullptr);
}

// Rect Construct
GameObject::GameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name) {
    sf::RectangleShape* newShape = new sf::RectangleShape(sf::Vector2f(sizeW, sizeH));
    Initialize(initialX, initialY, sizeW, sizeH, name, newShape);
}

GameObject::GameObject(float initialX, float initialY, int radius, std::string name) {
    sf::CircleShape* newShape = new sf::CircleShape(radius,radius);
    Initialize(initialX, initialY, radius, radius, name, newShape);

}


GameObject::~GameObject() {
}

void GameObject::Initialize(float initialX, float initialY, int sizeW, int sizeH, std::string name, sf::Shape* shape) {
    _position.x = initialX;
    _position.y = initialY;
    _width = sizeW;
    _height = sizeH;
    _name = name;


    shape->setFillColor(sf::Color::Blue);
    shape->setPosition(initialX, initialY);

    ptr_shape = shape;

}

sf::Shape* GameObject::GetShape() {
    return ptr_shape;
}


sf::Shape* GameObject::GetShape() const {
    return ptr_shape;
}


void GameObject::Update(GameObjectManager* gameObjectManager) {
}

void GameObject::Render() {
}

void GameObject::SetPosition(float x, float y) {
    _position.x = x;
    _position.y = y;
    ptr_shape->setPosition(_position.x, _position.y);
}

sf::Vector2f GameObject::GetPosition() const {
    return _position;
}

int GameObject::GetWidth() const {
    return _width;
}

int GameObject::GetHeight() const {
    return _height;
}


std::string GameObject::GetName() const {
    return _name;
}


void GameObject::SetSize(int width, int height) {
    _width = width;
    _height = height;
}


void GameObject::SetScale(float scaleX, float scaleY) {
    ptr_shape->setScale(scaleX, scaleY);
}

sf::Vector2f GameObject::GetScale() const {
    return ptr_shape->getScale();
}

void GameObject::SetRotation(float angle) {
    ptr_shape->setRotation(angle);
}

int GameObject::GetRotation() const {
    return ptr_shape->getRotation();
}

bool GameObject::GetIsCollidable() const {
    return _isCollidable;
}