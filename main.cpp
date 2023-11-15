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
#include "Border.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "RendererManager.h"
#include "LevelManager.h"
#include <iostream>


int main(int argc, char** argv) {
    RendererManager* rendererManager = new RendererManager(1000, 1000);

    GameObjectManager* gameObjectManager = new GameObjectManager;



    InputManager inputManager;
    LevelManager levelManager;

    levelManager.Initialize();
    levelManager.LoadLevel(gameObjectManager, rendererManager->GetWindow());

    //Brick* brick1 = new Brick(500, 500, 300, 300, "Brick");
    //gameObjectManager->AddObject(brick1);






    //Ball* ball1 = new Ball(300, 100, 10, "Ball");

    Canon* canon1 = new Canon(450, 750, 100, 50, "Canon");
    canon1->GetShape()->setFillColor(sf::Color::Red);

    Border* border1 = new Border(0, 0, 15, rendererManager->GetWinHeight(), "Border");
    Border* border2 = new Border(rendererManager->GetWinWidth() - 15, 0, 15, rendererManager->GetWinHeight(), "Border");
    Border* border3 = new Border(0, 0, rendererManager->GetWinWidth(), 15, "Border");


    gameObjectManager->AddObject(border1);
    gameObjectManager->AddObject(border2);
    gameObjectManager->AddObject(border3);

    gameObjectManager->AddObject(canon1);

    //gameObjectManager->AddObject(ball1);









    // GameLoop
    bool clicked = false;
    while (rendererManager->GetWindow()->isOpen()) {
        /*ball1->SetOrientation(1,0);*/




        std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
        sf::Vector2i mousePosI = inputManager.GetMousePosition(rendererManager);

        sf::Vector2f mousePosF(mousePosI.x, mousePosI.y);

        canon1->RotateTowardsMouse(mousePosI);

        if (inputManager.Update(rendererManager->GetWindow()) == 1) {
            canon1->Shoot(mousePosF, gameObjectManager);
            //clicked = true;
            //ball1->SetPosition(mousePosF.x, mousePosF.y);
            //ball1->SetSpeed(100);
            //ball1->SetOrientation(1,-1);

        }

        //if (clicked == false)
        //{
        //    ball1->SetPosition(mousePosF.x, mousePosF.y);
        //}

        //brick1->SetPosition(mousePosF.x, mousePosF.y);
        //brick1->SetPosition(mousePosF.x, mousePosF.y);





        rendererManager->Update(entitiesAlive);
        GameNamespace::GameManager::Update();
        gameObjectManager->Update(gameObjectManager);
    }

    // # TODO Delete Memory

    return 0;
}