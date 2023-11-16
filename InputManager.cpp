#include "InputManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

InputManager::InputManager() 
{
    _isMouseLeftPressed = false;
    _previousMousePosition = sf::Vector2i(0, 0);
    sf::Event* newEvent = new sf::Event;
    sf_event = newEvent;
}

InputManager::~InputManager() 
{
    delete sf_event;
}

int InputManager::Update(sf::RenderWindow* window) 
{
    if (window->pollEvent(*sf_event)) 
    {

        if (sf_event->type == sf::Event::Closed) {
            window->close();
        }

        if (CheckMouseLeftButtonPressed()) 
        {
            return 1;
        }

        return 0;
    }
}

bool InputManager::CheckMouseLeftButtonPressed() 
{
    // Check if the left mouse button is pressed
    if (sf_event->type == sf::Event::MouseButtonPressed && sf_event->mouseButton.button == sf::Mouse::Left) 
    {
        return true; // Return true if left mouse button is pressed
    }
    return false; // Return false if left mouse button is not pressed
}

sf::Vector2i InputManager::GetMouseMovement() 
{
    sf::Vector2i currentPosition = sf::Mouse::getPosition();

    // Calculate and return the mouse movement since the previous frame
    sf::Vector2i mouseMovement;
    mouseMovement.x = currentPosition.x - _previousMousePosition.x;
    mouseMovement.y = currentPosition.y - _previousMousePosition.y;
    _previousMousePosition = currentPosition;  // Update the previous position
    return mouseMovement;
}

sf::Vector2i InputManager::GetMousePosition(RendererManager* rendererManager) 
{
    // Get the current mouse position relative to the window
    const sf::RenderWindow* window = rendererManager->GetWindow();
    sf::Vector2i currentPosition = sf::Mouse::getPosition((*window));
    return currentPosition;
}
