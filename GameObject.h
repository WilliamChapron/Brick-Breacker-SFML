#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
    // Constructor
    GameObject();
    GameObject(float initialX, float initialY, int sizeW, int sizeH);
    // Destructor
    ~GameObject();

    // Base Methods
    virtual void Initialize(float initialX, float initialY, int sizeW, int sizeH);
    virtual void Update();
    virtual void Render();


    /*
        Set
    */
    void SetPosition(float x, float y);

    /*
        Get
    */
    sf::Vector2f GetPosition() const;
    sf::RectangleShape* GetShape();

// Accessible by child
protected:
    sf::RectangleShape* ref_shape;
    // Size
    int _height;
    int _width;
    sf::Vector2f _position;


private:

};




