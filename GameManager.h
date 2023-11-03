#pragma once

class GameManager {
public:
    GameManager();
    ~GameManager();

    void Initialize();
    void StartGame();
    void Update(float deltaTime);
    void Render();
};
