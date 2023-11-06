#include "GameObject.h"

GameObject::GameObject() {
    Initialize(0.0f, 0.0f, 1, 1, nullptr);
}

// Rect Construct
GameObject::GameObject(float initialX, float initialY, int sizeW, int sizeH) {
    sf::RectangleShape* newShape = new sf::RectangleShape(sf::Vector2f(sizeW, sizeH));
    Initialize(initialX, initialY, sizeW, sizeH, newShape);
}

GameObject::GameObject(float initialX, float initialY, int radius) {
    sf::CircleShape* newShape = new sf::CircleShape(radius,radius);
    Initialize(initialX, initialY, radius, radius, newShape);

}


GameObject::~GameObject() {
}

void GameObject::Initialize(float initialX, float initialY, int sizeW, int sizeH, sf::Shape* shape) {
    _position.x = initialX;
    _position.y = initialY;
    _width = sizeW;
    _height = sizeH;


    shape->setFillColor(sf::Color::Blue);
    shape->setPosition(initialX, initialY);

    ptr_shape = shape;

}

sf::Shape* GameObject::GetShape() {
    return ptr_shape;
}


void GameObject::Update() {
}

void GameObject::Render() {
}

void GameObject::SetPosition(float x, float y) {
    _position.x = x;
    _position.y = y;
}

sf::Vector2f GameObject::GetPosition() const {
    return _position;
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