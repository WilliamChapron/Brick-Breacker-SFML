#include "GameObjectManager.h"


// #TODO faire texture manager, introduire priorité de draw poru les texture ou les dessin, chaque objet a une priorité pour passer par dessus l'autre pendant le draw


GameObjectManager::GameObjectManager() {
    objvect_objects = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager() {
}

void GameObjectManager::Update(GameObjectManager* gameObjectManager) {
    for (GameObject* object : *objvect_objects) {
        object->Update(gameObjectManager);
    }
}


void GameObjectManager::AddObject(GameObject* object) {
    if (objvect_objects->size() < RendererManager::maxObjects) {
        objvect_objects->push_back(object);
    }
    
}

void GameObjectManager::RemoveObject(GameObject* object) {
    auto iterator = std::find(objvect_objects->begin(), objvect_objects->end(), object); // Return objvect_objects.end() if not finded
    if (iterator != objvect_objects->end()) {
        delete object;  
        objvect_objects->erase(iterator);
    }


}

std::vector<GameObject*> * GameObjectManager::FindObjectsByName(std::string name) {
    std::vector<GameObject*> * objectsByName = new std::vector<GameObject*>();
    for (GameObject* object : *objvect_objects) {
        if (object->GetName() == name) {
            objectsByName->push_back(object);
        }
    }
    return objectsByName;
}

std::vector<GameObject*> * GameObjectManager::GetAllObjects() {
    return objvect_objects;
}


int GameObjectManager::GetObjectsNumber() {
    return objvect_objects->size();
}

void GameObjectManager::Clear() {
    for (GameObject* object : *objvect_objects) {
        delete object;
    }
    objvect_objects->clear();
}
