#include "RendererManager.h"

#include <SFML/Graphics.hpp>
#include "GameObject.h"

RendererManager::RendererManager(int width, int height) {
    sf_window = new sf::RenderWindow(sf::VideoMode(width, height), "SFML Window");
    _winWidth = width;
    _winHeight = height;
}

RendererManager::~RendererManager() {
    delete sf_window;
}

void RendererManager::Initialize() {
}


void RendererManager::Update(std::vector<GameObject*> * aliveObjects) {
    Draw(aliveObjects);
}

void RendererManager::Draw(std::vector<GameObject*> * aliveObjects) {
    sf_window->clear();

    for (const GameObject* object : *aliveObjects) {
        const sf::Shape* shape = object->GetShape();
        sf_window->draw(*shape);
    }

    sf_window->display();
}

sf::RenderWindow* RendererManager::GetWindow() const {
    return sf_window;

}
int RendererManager::GetWinWidth() {
    return _winWidth;
}

int RendererManager::GetWinHeight() {
    return _winHeight;
}