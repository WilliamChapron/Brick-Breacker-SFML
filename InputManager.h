#pragma once


class RendererManager;
#include <SFML/Graphics.hpp>

class InputManager {
public:
    // Constructor
    InputManager();
    // Destructor
    ~InputManager();




    int Update(sf::RenderWindow* window);


    bool CheckMouseLeftButtonPressed();

    sf::Vector2i GetMouseMovement();     // Get mouse move from previous mouse position
    sf::Vector2i GetMousePosition(RendererManager* rendererManager);     // Get mouse pos



private:
    sf::Event* sf_event;
    bool _isMouseLeftPressed;
    sf::Vector2i _previousMousePosition;
};
