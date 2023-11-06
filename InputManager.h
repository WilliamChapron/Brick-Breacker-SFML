#pragma once

#include <SFML/Window.hpp>

class InputManager {
public:
    // Constructor
    InputManager();
    ~InputManager();


    void Update();


    bool IsMouseLeftButtonPressed() const;

    sf::Vector2i GetMouseMovement() const;     // Get mouse move from previous mouse position



private:
    sf::Event sf_event;
    bool _isMouseLeftPressed;
    sf::Vector2i _previousMousePosition;
};
