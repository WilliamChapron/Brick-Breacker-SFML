#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include "Canon.h"
#include "Ball.h"

class RendererManager {
public:
    RendererManager(int width, int height);
    ~RendererManager();

    void Initialize();
    void Update(std::vector<GameObject*>* aliveObjects);
    void Draw(std::vector<GameObject*>* aliveObjects);

    sf::RenderWindow* GetWindow() const;
    int GetWinWidth();
    int GetWinHeight();


    static const int maxObjects = 100;

private:
    sf::RenderWindow* sf_window;
    int _winWidth;
    int _winHeight;
};