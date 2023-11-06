#pragma once

class GameManager {
public:
    GameManager();
    ~GameManager();

    void Initialize();
    void StartGame();
    void Update();

    float GetDeltaTime() const;

private:
    float deltaTime;         
    float gameSpeed;         
    bool isGamePaused;       
    float realTimeElapsed;   
    float gameTimeElapsed;   

    // refresh interval (FPS)
    float targetFrameTime;

    void UpdateDeltaTime();  
};
