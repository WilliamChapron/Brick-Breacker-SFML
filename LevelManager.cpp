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

void LevelManager::LoadLevel(GameObjectManager*gameObjectManager) 
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

        for (const Rect brick : bricks) {
            std::cout << brick.x << std::endl;
        }

        Canon* canon1 = new Canon(100, 150, 200, 100, "Canon");
        Canon* canon2 = new Canon(300, 250, 200, 100, "Canon");
        Canon* canon3 = new Canon(500, 350, 200, 100, "Canon");
        //Canon* canon2 = new Canon(400, 250, 200, 100, "Canon");
        gameObjectManager.AddObject(canon1);
        gameObjectManager.AddObject(canon2);
        gameObjectManager.AddObject(canon3);
        gameObjectManager.AddObject(canon3);

        _isLevelLoaded = true;
    }
    
}

void LevelManager::Update() {
    
}