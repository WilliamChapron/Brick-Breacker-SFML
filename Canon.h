#pragma once

#include "PhysicalGameObject.h"

class Canon : public PhysicalGameObject {
public:
    // Constructor
    Canon();
    Canon(float initialX, float initialY, float width, float height, std::string name);

    // Destructor
    ~Canon();



private:

};

// TO-THINK - Canon control is not only orientation inverse but also specific control de