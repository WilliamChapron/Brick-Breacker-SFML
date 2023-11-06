#pragma once
#include "GameObject.h"

class Ball : public GameObject {
public:
    // Constructor
    Ball();
    Ball(float initialX, float initialY, float radius);
    ~Ball();

    void Initialize(float initialX, float initialY, float radius);

    // Override de la fonction CheckCollision de la classe de base

private:
    // Autres membres de classe spécifiques à la balle, le cas échéant.
    int _radius;
};