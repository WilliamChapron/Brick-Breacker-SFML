#pragma once

namespace sf 
{
    class RenderWindow;
}

class GameObject;
#include <vector>

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

    static int _winWidth;
    static int _winHeight;

private:
    sf::RenderWindow* sf_window;

};