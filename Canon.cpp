#include "Canon.h"
#include "Ball.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include <string>
#include <iostream>

Canon::Canon() : PhysicalGameObject() {
}

Canon::Canon(float initialX, float initialY, float width, float height, std::string name) : PhysicalGameObject(initialX, initialY, width, height, name)
{
    _hasToCollide = false;
    _isCollidable = false;
    sf::Vector2f origin = this->GetShape()->getOrigin();
    sf::Vector2f setOrigin(width / 2.f, height / 2.f);
    this->GetShape()->setOrigin(setOrigin);
}

Canon::~Canon() {

}

void Canon::RotateTowardsMouse(sf::Vector2i mousePosition) {



    sf::Vector2f canonPosition = this->GetPosition();
    sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    sf::Vector2f directionVector = mousePositionFloat - canonPosition;
    float angle = atan2(directionVector.y, directionVector.x) * 180 / 3.14159;

    //std::cout << this->GetRotation() << std::endl;



    /*sf::vector2f neworigin();
    this->setorigin(neworigin);*/


    if (angle >= -160 && angle <= -20)
    {
        this->SetRotation(angle);
    }

    /*if (this->GetRotation() != 200) {
        this->SetRotation(angle);
    }*/



    //// #TODO - Ajuster la position du canon pour que la rotation se fasse � partir de son centre mais la rotation est bloqu�
    //sf::Vector2f newCanonPosition = sf::Vector2f(canonPosition.x - this->GetWidth() / 2, canonPosition.y - this->GetHeight() / 2);
    //this->SetPosition(newCanonPosition.x, newCanonPosition.y);

    //// #TODO _ la solution serait d'utiliser setOrigin *


}

void Canon::Shoot(sf::Vector2f targetPosition, GameObjectManager* gameObjectManager) {


    sf::Vector2f canonPosition = this->GetPosition();
    sf::Vector2f direction = targetPosition - canonPosition;
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);


    //std::cout << canonPosition.x << std::endl;
    //std::cout << canonPosition.y << std::endl;

    if (targetPosition.y <= canonPosition.y - this->GetHeight()) {
        // Normalisation du vecteur de direction
        direction.x /= magnitude;
        direction.y /= magnitude;
        Ball* objectBall = new Ball(canonPosition.x - 10, canonPosition.y, 10, "Ball");
        objectBall->SetOrientation(direction.x, -1);
        objectBall->SetSpeed(300);
        gameObjectManager->AddObject(objectBall);
    }





}