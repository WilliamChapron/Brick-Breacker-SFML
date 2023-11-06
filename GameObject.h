#pragma once

#include <SFML/Graphics.hpp>s

class GameObject {
public:
    GameObject();
    GameObject(float initialX, float initialY);
    ~GameObject();

    virtual void Initialize(float initialX, float initialY);
    virtual void Update();
    virtual void Render();

    void SetPosition(float x, float y);

    sf::Vector2f GetPosition() const;



private:
    sf::Vector2f _position;
};




