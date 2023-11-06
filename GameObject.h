#pragma once

#include <SFML/Graphics.hpp>s

class GameObject {
public:
    // Constructor
    GameObject();
    GameObject(float initialX, float initialY, int size);
    ~GameObject();

    virtual void Initialize(float initialX, float initialY);
    virtual void Update();
    virtual void Render();

    void SetPosition(float x, float y);

    sf::Vector2f GetPosition() const;



private:
    sf::Vector2f _position;
};




