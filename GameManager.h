#pragma once

namespace GameNamespace {
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

        // #TODO - Delta time system accessible everywhere 
        
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

        // #TODO - Create The logic
        void UpdateDeltaTime();
    };
}



using namespace GameNamespace; // Make the GameManager class and its members accessible without prefixing
