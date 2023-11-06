#include "InputManager.h"
#include <iostream>

InputManager::InputManager() {
    _isMouseLeftPressed = false;
    _previousMousePosition = sf::Vector2i(0, 0);
    sf::Event* newEvent = new sf::Event;
    sf_event = newEvent;
}

InputManager::~InputManager() {
    delete sf_event;
}

void InputManager::Update(sf::RenderWindow* window) {
    if (window->pollEvent(*sf_event)) {
        if (sf_event->type == sf::Event::Closed) {
            window->close();
        }
        if (CheckMouseLeftButtonPressed()) {
            std::cout << "left click" << std::endl;
        }
        sf::Vector2i mouseMovement = GetMouseMovement();
        std::cout << mouseMovement.x << ":"  << mouseMovement.y << std::endl;


        
    }
}


bool InputManager::CheckMouseLeftButtonPressed() {
    if (sf_event->type == sf::Event::MouseButtonPressed && sf_event->mouseButton.button == sf::Mouse::Left) {
        return true;
    }
    return false;
}

sf::Vector2i InputManager::GetMouseMovement() {
    sf::Vector2i currentPosition = sf::Mouse::getPosition();
    sf::Vector2i mouseMovement;
    mouseMovement.x = currentPosition.x - _previousMousePosition.x;
    mouseMovement.y = currentPosition.y - _previousMousePosition.y;
    _previousMousePosition = currentPosition;  // Mettez à jour la position précédente
    return mouseMovement;
}
