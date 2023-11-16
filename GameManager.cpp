#include "GameManager.h"
#include <iostream>

namespace GameNamespace 
{
    // Static members initialization
    float GameManager::_deltaTime = 0.0f;
    float GameManager::_gameSpeed = 1.0f;
    bool GameManager::_isGamePaused = false;
    float GameManager::_realTimeElapsed = 0.0f;
    float GameManager::_gameTimeElapsed = 0.0f;
    float GameManager::_targetFrameTime = 1.0f / 60.0f;
    int GameManager::_score = 0;
    int GameManager::_ballUsed = 0;
    sf::Clock* GameManager::sf_clock = new sf::Clock;

    GameManager::GameManager() {
    }

    GameManager::~GameManager() {
    }

    void GameManager::Initialize() 
    {
        // Initialization of the GameManager
    }

    void GameManager::Update() 
    {
        // Update method for the GameManager
        _deltaTime = sf_clock->restart().asSeconds(); // Calculate the time elapsed since the last update

        // Uncomment the following line to print the delta time for debugging purposes
        /*std::cout << GameNamespace::GameManager::GetDeltaTime() << std::endl;*/

        // Check if the game is not paused
        if (!_isGamePaused) 
        {
            /*std::cout << "Game in progress" << std::endl;*/
        }
    }

    void GameManager::PauseGame() 
    {
        SetIsGamePaused(true);
    }

    void GameManager::ResumeGame() 
    {
        SetIsGamePaused(false);
    }

    void GameManager::LimitFrameRate() {
    }
}
