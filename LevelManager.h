#pragma once

class LevelManager {
public:
    LevelManager();
    ~LevelManager();

    void Initialize();
    void LoadLevel(int levelNumber);
    void Update();

private:
    int currentLevel;
    bool isLevelLoaded;

};