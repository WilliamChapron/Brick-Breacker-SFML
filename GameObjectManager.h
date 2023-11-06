#pragma once

#include <vector>
#include "GameObject.h"  

// TO DO

class GameObjectManager {
public:
    // Constructor
    GameObjectManager();
    ~GameObjectManager();


    void AddObject(GameObject* object);

    void RemoveObject(GameObject* object);

    // Mettre � jour tous les objets de jeu
    void Update(float deltaTime);

    void Clear();

private:
    std::vector<GameObject*> objvect_objects;  
};