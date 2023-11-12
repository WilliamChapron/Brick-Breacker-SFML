#pragma once

#include <SFML/System/Vector2.hpp>

//namespace sf
//{
//    class Vector2f;
//}

class GameObjectManager;
class CollisionManager;

class GameObjectManager;
class GameManager;

#include "GameObject.h"
#include "CollisionManager.h"

#include <vector>
#include <string>

class PhysicalGameObject : public GameObject {
public:
    // Constructor 
    PhysicalGameObject();
    PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name);
    PhysicalGameObject(float initialX, float initialY, int radius, std::string name);


    void Update(GameObjectManager* gameObjectManager) override;
    // Logic
    void Move();

    virtual void CheckCollideState(PhysicalGameObject* object);
    virtual void OnCollisionEnter();
    virtual void OnCollisionStay();
    virtual void OnCollisionExit();

    /*
        Get
    */
    sf::Vector2f GetOrientation() const;
    int GetSpeed() const;

    /*
        Set
    */
    void SetOrientation(float x, float y);
    void SetSpeed(int speed);

    virtual sf::FloatRect GetBoundingBox() const;
    virtual void HandleCollision(CollisionFace face);

protected:
    int _moveState;
    float _speed; 
    sf::Vector2f _orientation;

    std::vector<PhysicalGameObject*> objvect_collisionObject;

    sf::Shape* ptr_shape;
};
