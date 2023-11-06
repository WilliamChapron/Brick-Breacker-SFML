#pragma once
#include "GameObject.h"

class Border : public GameObject {
public:
    // Constructor
    Border();
    Border(float initialX, float initialY, float width, float height);
    ~Border();

    void Initialize(float initialX, float initialY, float width, float height);
    void Update();
    void Render();

private:
};