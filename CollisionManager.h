#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Ball.h" 
#include "Brick.h"  

enum class CollisionFace {
    None,
    Left,
    Right,
    Top,
    Bottom
};

class CollisionManager {
public:
    static CollisionFace DetectCollisionFace(const sf::FloatRect& rect1, const sf::FloatRect& rect2);

    static void CheckBallBrickCollisions(Ball* ball, std::vector<Brick*>& bricks);

    static void HandleCollision(Ball* ball, Brick* brick, CollisionFace face);
    static void CheckBallBrickCollisions(Ball* ball, std::vector<Brick*>& bricks);


private:
    static void HandleBallBrickCollision(Ball* ball, Brick* brick, CollisionFace face);
};

