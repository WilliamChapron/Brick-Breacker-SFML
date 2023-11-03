#pragma once

#include "GameObject.h" // Incluez le fichier d'en-tête de GameObject

class Entity : public GameObject {
public:
    // Constructeurs
    Entity();
    Entity(float initialX, float initialY);

    // Initialise l'entité avec une position initiale
    void Initialize(float initialX, float initialY);

    // Met à jour l'entité (peut être redéfini par des classes dérivées)
    virtual void Update();

    // Rend l'entité (peut être redéfini par des classes dérivées)
    virtual void Render();

    // Gère les collisions avec d'autres entités
    void Collide(Entity& other);

    // Déplace l'entité d'un déplacement relatif
    void Move(float dx, float dy);

    // Obtient la vitesse de l'entité
    sf::Vector2f GetVelocity() const;

protected:
    sf::Vector2f velocity; // Vitesse de l'entité
};
