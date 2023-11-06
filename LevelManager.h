#pragma once

class LevelManager {
public:
    // Constructor
    LevelManager();
    ~LevelManager();

    void Initialize();
    void LoadLevel(int levelNumber);
    void Update();

private:
    int currentLevel;
    bool isLevelLoaded;

};