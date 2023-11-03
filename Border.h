#pragma once
#include "GameObject.h"

class Border : public GameObject {
public:
    Border();
    Border(float initialX, float initialY, float width, float height);

    void Initialize(float initialX, float initialY, float width, float height);
    void Update();
    void Render();

private:
    float width;
    float height;
};