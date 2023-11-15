#pragma once
#include "GameObject.h"

class Border : public GameObject {
public:
    // Constructor
    Border();
    Border(float initialX, float initialY, float width, float height, std::string name);
    ~Border();

private:
};