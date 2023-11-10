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
#include "Brick.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "RendererManager.h"
#include "LevelManager.h"
#include <iostream>


int main(int argc, char** argv) {
    RendererManager* rendererManager = new RendererManager(1000,1000);

    GameObjectManager* gameObjectManager = new GameObjectManager;
    


    InputManager inputManager;      
    LevelManager levelManager;

    //levelManager.Initialize();
    //levelManager.LoadLevel(gameObjectManager, rendererManager.GetWindow());

    Brick* brick1 = new Brick(100, 200, 100, 200, "Brick");
    gameObjectManager->AddObject(brick1);

    Ball* ball1 = new Ball(100, 200, 200, "Ball");
    gameObjectManager->AddObject(ball1);
    

    //Ball* ball2 = new Ball(100, 200, 200, "Ball");
    //gameObjectManager->AddObject(ball2);



    // GameLoop
    while (rendererManager->GetWindow()->isOpen()) {
        /*ball1->SetOrientation(1,0);*/
        
        inputManager.Update(rendererManager->GetWindow());
        std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
        sf::Vector2i mousePosition = inputManager.GetMousePosition(rendererManager);

        sf::Vector2f mousePos(mousePosition.x,mousePosition.y);
        brick1->SetPosition(mousePos.x, mousePos.y);
        rendererManager->Update(entitiesAlive);
        GameNamespace::GameManager::Update();
        gameObjectManager->Update(gameObjectManager);
    }

    // # TODO Delete Memory

    return 0;
}