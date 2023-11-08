#include "LevelManager.h"


LevelManager::LevelManager() : _currentLevel(0), _isLevelLoaded(false) 
{

}

LevelManager::~LevelManager() 
{

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

        for (const Rect brick : bricks) {
            Canon* canon1 = new Canon((winSize.x * brick.x)/100, (winSize.y * brick.y)/100, brick.width, brick.height, "Canon");
            std::cout << winSize.x / brick.x << std::endl;
            std::cout << winSize.y / brick.y << std::endl;
            gameObjectManager->AddObject(canon1);
        }

        _isLevelLoaded = true;
    }
    
}

void LevelManager::Update() {
    
}