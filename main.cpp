/*
   ***********************
   CODE STYLE DESCRIPTION
   ***********************
*/

// - Pascal Case For Class 
// - Pascal Case For Functions
// - Camel Case For Var 
// - Add _type after normal var (optional for unimportant types, but don't need to put "_" if no type is specified) 
// - Add type_ before class member var (optional for unimportant types, but always put the "_") 
// - Don't need to specify _ or type with args var
// - Multiple Line commentary for Functions or Methods description, like: ( /* - Commentary - */ )
// - One-line commentary for one-line Operations, next to the line, like: ( // $Commentary )
// - To Think commentary: #TOTHINK - $
// - To Do commentary: #TODO - $

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

int main(int argc, char** argv) 
{
    // Create RendererManager and GameObjectManager instances
    RendererManager* rendererManager = new RendererManager(1920, 1080);
    GameObjectManager* gameObjectManager = new GameObjectManager;

    // Create Canon instance and set its properties
    Canon* canon1 = new Canon(960, 950, 100, 50, "Canon");
    canon1->GetShape()->setFillColor(sf::Color::Red);

    // Create Border instances
    Border* border1 = new Border(0, 0, 15, rendererManager->GetWinHeight(), "Border");
    Border* border2 = new Border(rendererManager->GetWinWidth() - 15, 0, 15, rendererManager->GetWinHeight(), "Border");
    Border* border3 = new Border(0, 0, rendererManager->GetWinWidth(), 15, "Border");

    // Add objects to GameObjectManager
    gameObjectManager->AddObject(border1);
    gameObjectManager->AddObject(border2);
    gameObjectManager->AddObject(border3);
    gameObjectManager->AddObject(canon1);

    // Create InputManager and LevelManager instances
    InputManager inputManager;
    LevelManager levelManager;

    // Initialize and load the level
    levelManager.Initialize();
    levelManager.LoadLevel(gameObjectManager, rendererManager->GetWindow());

    // Game Loop
    while (rendererManager->GetWindow()->isOpen()) 
    {
        // Get all alive game objects and mouse position
        std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
        sf::Vector2i mousePosI = inputManager.GetMousePosition(rendererManager);
        sf::Vector2f mousePosF(mousePosI.x, mousePosI.y);

        canon1->RotateTowardsMouse(mousePosI);

        // Check for input to shoot
        if (inputManager.Update(rendererManager->GetWindow()) == 1) 
        {
            canon1->Shoot(mousePosF, gameObjectManager);
        }

        // Manager Updates
        rendererManager->Update(entitiesAlive);
        GameNamespace::GameManager::Update();
        gameObjectManager->Update(gameObjectManager);

        // Check for game over condition
        if (gameObjectManager->FindObjectsByName("Brick")->size() == 0) 
        {
            std::cout << "Game Over, No more bricks" << std::endl;
            return 1;
        }
    }

    // Clean up memory
    delete gameObjectManager;
    delete rendererManager;

    return 0;
}
