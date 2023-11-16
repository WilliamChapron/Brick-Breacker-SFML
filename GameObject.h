#pragma once

#include <SFML/Graphics.hpp>
class GameObjectManager;
class RendererManager;

class GameObject {
public:
    // Constructor
    GameObject();
    // Rect Construct
    GameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name);
    // Circle Construct
    GameObject(float initialX, float initialY, int radius, std::string name);
    // Destructor
    ~GameObject();

    // Base Methods
    virtual void Initialize(float initialX, float initialY, int sizeW, int sizeH, std::string name, sf::Shape* shape);
    virtual void Update(GameObjectManager* gameObjectManager);


    /*
        Get
    */
    sf::Vector2f GetPosition() const;
    sf::Shape* GetShape();
    sf::Shape* GetShape() const;
    int GetWidth();
    int GetHeight();

    std::string GetName() const;

    bool GetHasToCollide() const;
    bool GetIsCollidable() const;


    /*
    Set
    */
    void SetPosition(float x, float y);
    void SetSize(int width, int height);



    // 2d Transform
    void SetScale(float scaleX, float scaleY);
    sf::Vector2f GetScale() const;

    virtual void SetRotation(float angle);
    virtual int GetRotation() const;

    // Accessible by child
protected:
    sf::Shape* ptr_shape;
    // Size
    int _height;
    int _width;
    sf::Vector2f _position;

    // Name 
    std::string _name;


    bool _hasToCollide;
    bool _isCollidable;

private:

};



