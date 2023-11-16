#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace GameNamespace {
    class GameManager {
    public:
        GameManager();
        ~GameManager();

        static void Initialize();
        static void Update();
        static void PauseGame();
        static void ResumeGame();
        static void LimitFrameRate();

        // Getters & Setters
        static float GetDeltaTime() {
            return _deltaTime;
        }

        static void SetDeltaTime(float deltaTime) {
            _deltaTime = deltaTime;
        }

        static float GetGameSpeed() {
            return _gameSpeed;
        }

        static void SetGameSpeed(float gameSpeed) {
            _gameSpeed = gameSpeed;
        }

        static bool IsGamePaused() {
            return _isGamePaused;
        }

        static void SetIsGamePaused(bool isGamePaused) {
            _isGamePaused = isGamePaused;
        }

        static float GetRealTimeElapsed() {
            return _realTimeElapsed;
        }

        static void SetRealTimeElapsed(float realTimeElapsed) {
            _realTimeElapsed = realTimeElapsed;
        }

        static float GetGameTimeElapsed() {
            return _gameTimeElapsed;
        }

        static void SetGameTimeElapsed(float gameTimeElapsed) {
            _gameTimeElapsed = gameTimeElapsed;
        }

        static float GetTargetFrameTime() {
            return _targetFrameTime;
        }

        static void SetTargetFrameTime(float targetFrameTime) {
            _targetFrameTime = targetFrameTime;
        }

        static int GetScore() {
            return _score;
        }

        static void SetScore(int score) {
            _score = score;
        }

        static float _deltaTime;
        static float _gameSpeed;
        static bool _isGamePaused;
        static float _realTimeElapsed;
        static float _gameTimeElapsed;
        static float _targetFrameTime;
        static int _score;
        static int _ballUsed;
        static sf::Clock* sf_clock;

    private:
    };
}
