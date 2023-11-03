#pragma once

#include "GameObject.h" // Incluez le fichier d'en-t�te de GameObject

class Entity : public GameObject {
public:
    // Constructeurs
    Entity();
    Entity(float initialX, float initialY);

    // Initialise l'entit� avec une position initiale
    void Initialize(float initialX, float initialY);

    // Met � jour l'entit� (peut �tre red�fini par des classes d�riv�es)
    virtual void Update();

    // Rend l'entit� (peut �tre red�fini par des classes d�riv�es)
    virtual void Render();

    // G�re les collisions avec d'autres entit�s
    void Collide(Entity& other);

    // D�place l'entit� d'un d�placement relatif
    void Move(float dx, float dy);

    // Obtient la vitesse de l'entit�
    sf::Vector2f GetVelocity() const;

protected:
    sf::Vector2f velocity; // Vitesse de l'entit�
};
