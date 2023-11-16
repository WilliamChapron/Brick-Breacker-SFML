#include "GameObjectManager.h"


GameObjectManager::GameObjectManager() 
{
    objvect_objects = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager() {
}

void GameObjectManager::Update(GameObjectManager* gameObjectManager) 
{
    // Update each object in the manager
    for (GameObject* object : *objvect_objects) 
    {
        object->Update(gameObjectManager);
    }
}

void GameObjectManager::AddObject(GameObject* object)
{
    // Add an object to the manager, respecting the maximum object limit
    if (objvect_objects->size() < RendererManager::maxObjects) 
    {
        objvect_objects->push_back(object);
    }
}

void GameObjectManager::RemoveObject(GameObject* object) 
{
    // Remove an object from the manager
    auto iterator = std::find(objvect_objects->begin(), objvect_objects->end(), object);
    if (iterator != objvect_objects->end()) 
    {
        objvect_objects->erase(iterator);
        delete object;
    }
}

std::vector<GameObject*>* GameObjectManager::FindObjectsByName(std::string name) 
{
    // Find objects in the manager by their name
    std::vector<GameObject*>* objectsByName = new std::vector<GameObject*>();
    for (GameObject* object : *objvect_objects) 
    {
        if (object->GetName() == name) 
        {
            objectsByName->push_back(object);
        }
    }
    return objectsByName;
}

std::vector<GameObject*>* GameObjectManager::GetAllObjects() 
{
    // Return a pointer to the vector of all objects in the manager
    return objvect_objects;
}

int GameObjectManager::GetObjectsNumber() 
{
    // Return the number of objects in the manager
    return objvect_objects->size();
}

void GameObjectManager::Clear() 
{
    // Clear the manager by deleting all objects
    for (GameObject* object : *objvect_objects)
    {
        delete object;
    }
    objvect_objects->clear();
}
