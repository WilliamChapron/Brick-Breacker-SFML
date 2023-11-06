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
#include "InputManager.h"
#include <iostream>


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML");


    PhysicalGameObject object(50, 50, 50, 50);

    InputManager inputManager;

    //GameLoop
    while (window->isOpen())
    {
        ////EVENT
        //sf::Event oEvent;
        //while (oWindow.pollEvent(oEvent))
        //{
        //    if (oEvent.type == sf::Event::Closed)
        //        oWindow.close();
        //}


        //UPDATE

        //DRAW
        window->clear();

        inputManager.Update(window);
        /*std::cout << check << std::endl;*/

        /*object.Move();
        oWindow.draw(*object.GetShape());*/


        window->display();
    }

    return 0;
}
