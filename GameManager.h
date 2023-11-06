#pragma once

class GameManager {
public:
    // Constructor
    GameManager();
    ~GameManager();

    void Initialize();
    void StartGame();
    void Update();

    float GetDeltaTime() const;

private:
    // Manage Time Var
    float _deltaTime;         
    float _gameSpeed;         
    bool _isGamePaused;       
    float _realTimeElapsed;   
    float _gameTimeElapsed;   

    // Refresh Interval (FPS)
    float _targetFrameTime;

    // Score
    int _score;

    // 
    void UpdateDeltaTime();  
};
