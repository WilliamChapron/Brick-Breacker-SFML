#pragma once

#include <iostream>
#include "GameObject.h"  
#include "RendererManager.h"  


// TO DO

class GameObjectManager {
public:
    // Constructor
    GameObjectManager();
    ~GameObjectManager();


    void AddObject(GameObject* object);

    void RemoveObject(GameObject* object);

    std::vector<GameObject*> * FindObjectsByName(std::string name);

    std::vector<GameObject*> * GetAllObjects();


    int GetObjectsNumber();

    void Update();

    void Clear();

private:
    std::vector<GameObject*> * objvect_objects;  
};