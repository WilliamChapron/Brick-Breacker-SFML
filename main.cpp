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

#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "Ball.h"
#include "Canon.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "RendererManager.h"
#include <iostream>


int main(int argc, char** argv) {
    RendererManager rendererManager(1000,1000);
    GameObjectManager gameObjectManager;
    InputManager inputManager;      

    Canon* canon1 = new Canon(100, 150, 200, 100, "Canon");
    Canon* canon2 = new Canon(300, 250, 200, 100, "Canon");
    Canon* canon3 = new Canon(500, 350, 200, 100, "Canon");
    //Canon* canon2 = new Canon(400, 250, 200, 100, "Canon");
    gameObjectManager.AddObject(canon1);
    gameObjectManager.AddObject(canon2);
    gameObjectManager.AddObject(canon3);
    gameObjectManager.AddObject(canon3);
    //gameObjectManager.RemoveObject(canon1);
    //std::vector<GameObject*> object = gameObjectManager.FindObjectsByName("Canone");


    //gameObjectManager.AddObject(canon2);

    // GameLoop
    while (rendererManager.GetWindow()->isOpen()) {
        inputManager.Update(rendererManager.GetWindow());
        std::vector<GameObject*> * entitiesAlive = gameObjectManager.GetAllObjects();
        rendererManager.Update(entitiesAlive);
        // UPDATE
        // 
        // 
        // DRAW
        /*rendererManager.DrawObjects();*/
    }

    //delete canon1;
    //delete ball1;

    return 0;
}