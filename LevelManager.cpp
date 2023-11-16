#include "LevelManager.h"
#include "Brick.h"
#include "GameObjectManager.h"


LevelManager::LevelManager() : _currentLevel(0), _isLevelLoaded(false)
{

}

LevelManager::~LevelManager()
{
    for (GameObject* object : _objectsPointer) {
        delete object;
    }

}

void LevelManager::Initialize()
{
    // Random Level here
    _randomGeneratedLevel = 1;

}

void LevelManager::LoadLevel(GameObjectManager* gameObjectManager, sf::RenderWindow* window)
{
    if (_currentLevel = !0) {
        std::string filename = "Levels/level" + std::to_string(_currentLevel) + ".json";
        std::ifstream file(filename);
        json data;
        file >> data;

        // Vect rect
        std::vector<Rect> bricks;

        for (const auto& brickData : data["bricks"]) {
            Rect brick;
            brick.x = brickData["x"];
            brick.y = brickData["y"];
            brick.width = brickData["width"];
            brick.height = brickData["height"];
            bricks.push_back(brick);
        }

        // Get window size 
        sf::Vector2u winSize = window->getSize();

        if (_objectsPointer.empty() == false)
        {
            for (GameObject* object : _objectsPointer) {
                delete object;
            }

            _objectsPointer.clear();
        }

        for (const Rect brick : bricks) {
            Brick* brick1 = new Brick((winSize.x * brick.x) / 100, (winSize.y * brick.y) / 100, brick.width, brick.height, "Brick");
            //std::cout << winSize.x / brick.x << std::endl;
            //std::cout << winSize.y / brick.y << std::endl;
            gameObjectManager->AddObject(brick1);
            _objectsPointer.push_back(brick1);
        }

        _isLevelLoaded = true;
    }

}

void LevelManager::Update() {

}