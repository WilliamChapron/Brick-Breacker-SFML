#pragma once
#include "GameObject.h"
#include "GameObjectManager.h"
#include "GameManager.h"

namespace GameNamespace {
    class GameManager;
}
class GameObjectManager;

class Brick : public GameObject {
public:
    // Constructor
    Brick();
    Brick(float initialX, float initialY, float width, float height, std::string name, int initialHealth = 3);
    ~Brick();

    void Update(GameObjectManager* gameObjectManager) override;

    /*
        Get / Set
    */
    void SetHealth(int health);
    void RemoveHealth(int amount);
    int GetHealth() const;

private:
    int _health;

};