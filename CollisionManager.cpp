#include "CollisionManager.h"

// Vérifie les collisions entre la balle et les briques
void CollisionManager::CheckBallBrickCollisions(Ball* ball, std::vector<Brick*>& bricks) {
    sf::FloatRect ballRect = ball->GetBoundingBox();

    // Parcourt toutes les briques
    for (Brick* brick : bricks) {
        sf::FloatRect brickRect = brick->GetBoundingBox();

        CollisionFace face = DetectCollisionFace(ballRect, brickRect);

        if (face != CollisionFace::None) {
            HandleBallBrickCollision(ball, brick, face);
        }
    }
}

// Gère la collision entre la balle et la brique
void CollisionManager::HandleBallBrickCollision(Ball* ball, Brick* brick, CollisionFace face) {
    switch (face) {
    case CollisionFace::Left:
        std::cout << "Collision avec la brique du côté gauche" << std::endl;
        break;
    case CollisionFace::Right:
        std::cout << "Collision avec la brique du côté droit" << std::endl;
        break;
    case CollisionFace::Top:
        std::cout << "Collision avec la brique en haut" << std::endl;
        break;
    case CollisionFace::Bottom:
        std::cout << "Collision avec la brique en bas" << std::endl;
        break;
    default:
        break;
    }

    // Effectue des actions supplémentaires en fonction de la collision, par exemple, supprime la brique
    brick->HandleCollision();

    // Ajuste la position ou la vélocité de la balle si nécessaire
    ball->HandleCollision(face);
}
