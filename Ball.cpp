#include "Ball.h"
#include "GameObject.h"
#include <string>
#include "CollisionManager.h"
#include <iostream>


Ball::Ball() : PhysicalGameObject() {

}

Ball::Ball(float initialX, float initialY, float radius, std::string name) : PhysicalGameObject(initialX, initialY, radius, name)
{
    _speed = 100;
    _moveState = 1;
    _hasToCollide = true;
    _isCollidable = true;
    _shouldBounce = false;


    //sf::Vector2f setorigin(radius, radius);
    //this->GetShape()->setOrigin(setorigin);
}




void Ball::OnCollisionEnter(GameObject* collideObject) {
    int faceState = CollisionNamespace::CollisionManager::DetectCollisionFace(this, collideObject);
    sf::Vector2f orientation = GetOrientation();
    //std::cout << "bouncing ball" << std::endl;

    ///// Face == Left
    if (faceState == 1) 
    {
        if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }


    }




    ///// Face == Right
    if (faceState == 2) 
    {
        if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= 1;
            orientation.y *= -1;
        }

        else if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= 1;
            orientation.y *= -1;
        }

    }
   


    /////Face == Top
    if (faceState == 3) 
    {
        if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= 1;
            orientation.y *= -1;
        }

        else if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= 0 && orientation.y <= 1)
        {
    
            orientation.x *= 1;
            orientation.y *= -1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= -1 && orientation.y <= 0)
        {
    
            orientation.x *= -1;
            orientation.y *= 1;
        }

    }
   


    /////Face == Bottom
    if (faceState == 4)
    {
        if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= -1 && orientation.y <= 0)
        {
            orientation.x *= 1;
            orientation.y *= -1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= 0 && orientation.y <= 1)
        {
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= -1 && orientation.x <= 0 && orientation.y >= 0 && orientation.y <= 1)
        {
            orientation.x *= -1;
            orientation.y *= 1;
        }

        else if (orientation.x >= 0 && orientation.x <= 1 && orientation.y >= -1 && orientation.y <= 0)
        {
            orientation.x *= 1;
            orientation.y *= -1;
        }
    }

   SetOrientation(orientation.x, orientation.y);
}




Ball::~Ball() {

}