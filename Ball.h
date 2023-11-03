#pragma once
#include "GameObject.h"

class Ball : public GameObject {
public:
    Ball();
    Ball(float initialX, float initialY, float radius);

    void Initialize(float initialX, float initialY, float radius);

    // Override de la fonction CheckCollision de la classe de base
    void CheckCollision() override;

private:
    // Autres membres de classe sp�cifiques � la balle, le cas �ch�ant.
};