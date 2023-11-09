#pragma once

#include <iostream>


#include <nlohmann/json.hpp> // Treat json
#include <fstream> // Syntax file
using json = nlohmann::json; // Using namespace

// SFML
#include <SFML/Graphics.hpp>

class Canon;
class GameObject;
class GameObjectManager;



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
    void LoadLevel(GameObjectManager* gameObjectManager, sf::RenderWindow* window);
    void Update();

private:
    int _randomGeneratedLevel;
    int _currentLevel;
    bool _isLevelLoaded;

    // Store object in memory
    std::vector<GameObject*> _objectsPointer;
};