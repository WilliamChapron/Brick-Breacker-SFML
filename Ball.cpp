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


    // # TODO Regler probl�me de cas sp�cial en top et left sa fait le probl�me en plus de right et bottom, probl�me de partout, tout d'abord faire 8 conditions, 

    // Left Right Case
    if (faceState <= 2) {
        //std::cout << faceState << std::endl;
        if (faceState == 2 && orientation.x == 1 && orientation.y == 1) {
            std::cout << "cas sp�cial" << std::endl;
            orientation.x = 1;
            orientation.y = -1;
        }
        else {
            //std::cout << "normal" << std::endl;
            orientation.x *= -1;
        }
        // Axe y don't move

        /*orientation.y = current*/

        // Axe x inverse
    }
    // Top Down case
    if (faceState > 2) {
        if (faceState == 4 && orientation.x == 1 && orientation.y == 1) {
            std::cout << "cas sp�cial" << std::endl;
            orientation.x = -1;
            orientation.y = 1;
        }
        else {
            //std::cout << "normal" << std::endl;
            orientation.y *= -1;
        }
        // Axe x don't move

        /*orientation.x = current */

        // Axe y inverse

    }
    SetOrientation(orientation.x, orientation.y);
}




Ball::~Ball() {

}