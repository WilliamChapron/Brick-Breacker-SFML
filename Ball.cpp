#include "Ball.h"

Ball::Ball() : PhysicalGameObject() {

}

Ball::Ball(float initialX, float initialY, float radius) : PhysicalGameObject(initialX, initialY, radius) {
}

Ball::~Ball() {
    
}
