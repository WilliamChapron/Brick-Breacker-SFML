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
    RendererManager* rendererManager = new RendererManager(1000, 1000);

    GameObjectManager* gameObjectManager = new GameObjectManager;

    InputManager inputManager;

    Canon* canon1 = new Canon(450, 750, 100, 100, "Canon");
    Brick* brick1 = new Brick(750, 100, 200, 50, "Brick");
    Brick* brick2 = new Brick(350, 100, 25, 25, "Brick");

    gameObjectManager->AddObject(canon1);
    gameObjectManager->AddObject(brick1);
    gameObjectManager->AddObject(brick2);

    bool isDraggingBrick = false;
    sf::Vector2f initialMousePos;
    Brick* draggedBrick = nullptr;

    // GameLoop
    while (rendererManager->GetWindow()->isOpen()) {
        std::vector<GameObject*>* entitiesAlive = gameObjectManager->GetAllObjects();
        sf::Vector2i mousePosI = inputManager.GetMousePosition(rendererManager);
        sf::Vector2f mousePosF(mousePosI.x, mousePosI.y);
        canon1->RotateTowardsMouse(mousePosI);

        if (inputManager.Update(rendererManager->GetWindow()) == 1) {
            canon1->Shoot(mousePosF, gameObjectManager);
        }

        bool isBrickCollision = CollisionNamespace::CollisionManager::RectCollision(brick1, brick2);

        if (isBrickCollision) {
            //std::cout << "Collision entre les briques !" << std::endl;
            // Affiche 1 si les briques entrent en collision
        }




        // TEMPORAIRE POUR TESTER LES COLLISIONS
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isDraggingBrick) {
            if (brick2->Contains(mousePosF)) {
                isDraggingBrick = true;
                draggedBrick = brick2;
                initialMousePos = mousePosF;
            }
        }

        if (isDraggingBrick) {
            sf::Vector2i mousePos = inputManager.GetMousePosition(rendererManager);
            sf::Vector2f mousePosF(mousePos.x, mousePos.y);

            sf::Vector2f delta = mousePosF - initialMousePos;
            draggedBrick->Move(delta);

            initialMousePos = mousePosF;

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isDraggingBrick = false;
                draggedBrick = nullptr;
            }
        }

        // Utilisez les zones englobantes pour détecter la face de collision
        CollisionNamespace::CollisionFace collisionFace = CollisionNamespace::CollisionManager::DetectCollisionFace(brick1->GetBoundingBox(), brick2->GetBoundingBox());

        switch (collisionFace) {
        case CollisionNamespace::CollisionFace::None:
            std::cout << "" << std::endl;
            break;
        case CollisionNamespace::CollisionFace::Left:
            std::cout << "Collision à gauche." << std::endl;
            break;
        case CollisionNamespace::CollisionFace::Right:
            std::cout << "Collision à droite." << std::endl;
            break;
        case CollisionNamespace::CollisionFace::Top:
            std::cout << "Collision en haut." << std::endl;
            break;
        case CollisionNamespace::CollisionFace::Bottom:
            std::cout << "Collision en bas." << std::endl;
            break;
        }

        rendererManager->Update(entitiesAlive);
        GameNamespace::GameManager::Update();
        gameObjectManager->Update(gameObjectManager);
    }

    // # TODO Delete Memory

    return 0;
}
