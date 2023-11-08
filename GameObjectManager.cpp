#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {
    objvect_objects = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager() {
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

    /*std::cout << "Contenu du vecteur objvect_objects : ";
    for (GameObject* obj : objvect_objects) {
        std::cout << obj->GetName() << std::endl;
    }
    std::cout << std::endl;*/

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

void GameObjectManager::Update() {
    for (GameObject* object : *objvect_objects) {
        object->Update();
    }
}

void GameObjectManager::Clear() {
    for (GameObject* object : *objvect_objects) {
        delete object;
    }
    objvect_objects->clear();
}
