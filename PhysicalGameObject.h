#pragma once

#include <SFML/System/Vector2.hpp>
#include "GameObject.h"
#include "GameObject.h"
#include "Brick.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include <vector>
#include <string>

class GameObjectManager;
class CollisionManager;

class GameManager;



class PhysicalGameObject : public GameObject {
public:
    // Constructor 
    PhysicalGameObject();
    PhysicalGameObject(float initialX, float initialY, int sizeW, int sizeH, std::string name);
    PhysicalGameObject(float initialX, float initialY, int radius, std::string name);


    void Update(GameObjectManager* gameObjectManager) override;
    // Logic
    void Move();

    virtual void CollisionUpdate();

    void CheckCollideState(PhysicalGameObject* object);
    virtual void OnCollisionEnter(GameObject* collideObject);
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



protected:
    int _moveState;
    float _speed;
    sf::Vector2f _orientation;

    std::vector<PhysicalGameObject*> objvect_collisionObject;
};