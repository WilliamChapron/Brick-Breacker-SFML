#include "GameObject.h"

GameObject::GameObject() {
    Initialize(0.0f, 0.0f, 1, 1);
}

GameObject::GameObject(float initialX, float initialY, int sizeW, int sizeH) {
    Initialize(initialX, initialY, sizeW, sizeH);
}

GameObject::~GameObject() {
}

void GameObject::Initialize(float initialX, float initialY, int sizeW, int sizeH) {
    _position.x = initialX;
    _position.y = initialY;
    _width = sizeW;
    _height = sizeH;

    sf::RectangleShape* newShape = new sf::RectangleShape(sf::Vector2f(sizeW, sizeH));
    newShape->setFillColor(sf::Color::Blue);
    newShape->setPosition(initialX, initialY);

    ref_shape = newShape;

}

sf::RectangleShape* GameObject::GetShape() {
    return ref_shape;
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
    ref_shape->setScale(scaleX, scaleY);
}

sf::Vector2f GameObject::GetScale() const {
    return ref_shape->getScale(); 
}

void GameObject::SetRotation(float angle) {
    ref_shape->setRotation(angle);
}

int GameObject::GetRotation() const {
    return ref_shape->getRotation();
}