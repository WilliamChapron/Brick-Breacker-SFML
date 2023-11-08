#pragma once

#include <iostream>
#include "GameObjectManager.h"

#include <nlohmann/json.hpp> // Treat json
#include <fstream> // Syntax file
using json = nlohmann::json; // Using namespace



struct Rect {
    int x;
    int y;
    int width;
    int height;
};

struct Circle {
    int x;
    int y;
    int radius;
};


class LevelManager {
public:
    // Constructor
    LevelManager();
    ~LevelManager();

    void Initialize();
    void LoadLevel(GameObjectManager* gameObjectManager);
    void Update();

private:
    int _randomGeneratedLevel;
    int _currentLevel;
    bool _isLevelLoaded;
};