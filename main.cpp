/* 
    ***********************
    CODE STYLE DESCRIPTION
    ***********************
*/ 

// - Pascal Case For Class 
// - Pascal Case For Functions
// - Camel Case For Var 
// - Add _type after normal var (facultatif for not important type but don't need to put "_" if no type write) 
// - Add type_ before class member var (facultatif for not important type but need always put the "_") 
// - Don't need specifiy _ or type with args var
// - Multiple Line commentary for Functions or Methods decription, like : ( /* - Commentary - */ )
// - One line commentary for one line Operation, next to the line, like : ( // $Commentary )
// - To Think commentary : #TOTHINK - $
// - To Do commentary : #TODO - $





/*
    CODE STYLE DESCRIPTION
*/

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "Ball.h"
#include "Canon.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include <iostream>
#include "GameManager.h"


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML");


    Canon canon(150, 150, 150, 150);
    Ball ball(100, 100, 50);
    Ball ball2(25, 105, 50);

    CollisionManager collisionManager;


    InputManager inputManager;

    //GameLoop
    while (window->isOpen())
    {
        GameNamespace::GameManager::Update();

        //UPDATE

        //DRAW
        window->clear();

        inputManager.Update(window);
        /*std::cout << check << std::endl;*/

        /*object.Move();*/

        //object.SetRotation(65);
        //std::cout << object.GetRotation() << std::endl;

        //object.SetScale(30,30);
        
        /*std::cout << collisionManager.CircleRectCollision(canon,ball) << std::endl;*/


        window->draw(*canon.GetShape());
        window->draw(*ball.GetShape());
        window->draw(*ball2.GetShape());


        window->display();
    }

    return 0;
}
