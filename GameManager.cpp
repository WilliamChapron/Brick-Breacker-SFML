#include "GameManager.h"
#include <iostream>

namespace GameNamespace {
    float GameManager::_deltaTime = 0.0f;
    float GameManager::_gameSpeed = 1.0f;
    bool GameManager::_isGamePaused = false;
    float GameManager::_realTimeElapsed = 0.0f;
    float GameManager::_gameTimeElapsed = 0.0f;
    float GameManager::_targetFrameTime = 1.0f / 60.0f;
    int GameManager::_score = 0;
    sf::Clock* GameManager::sf_clock = new sf::Clock;

    GameManager::GameManager() {
    }

    GameManager::~GameManager() {
    }

    void GameManager::Initialize() {
    }

    void GameManager::Update() {
        sf::Time frameTime = sf_clock->restart();
        _deltaTime = frameTime.asSeconds();
        /*std::cout << _deltaTime << std::endl;*/

        // return time elapsed since last update and convert it in second with as second
        // Game Pause
        if (!_isGamePaused) {
            /*std::cout << "Jeu en cours" << std::endl;*/
        }
    }

    void GameManager::PauseGame() {
        SetIsGamePaused(true); 
    }

    void GameManager::ResumeGame() {
        SetIsGamePaused(false); 
    }

    void GameManager::LimitFrameRate() {
    }
}
