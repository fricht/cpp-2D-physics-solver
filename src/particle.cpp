#include "particle.hpp"


void Particle::simulate(float delta_t) {
    velocity += acceleration * delta_t;
    position += velocity * delta_t;
};


void Particle::draw(sf::RenderWindow & window, Camera & camera) {
    sf::CircleShape p_shape(radius);
    p_shape.setFillColor(color);
    p_shape.setPosition(position - sf::Vector2f(radius, radius));
    // apply cam
    camera.apply_cam(p_shape);
    window.draw(p_shape);
};


void Particle::static_collision(sf::Vector2f & floor) {
    // normalizing
    float length = std::sqrt(floor.x * floor.x + floor.y * floor.y);
    if (length == 0) {
        floor = sf::Vector2f(0, 0);
    } else {
        floor /= length;
    }
    float dot;
    // apply for velocity
    dot = velocity.x * floor.x + velocity.y * floor.y;
    velocity = floor * dot;
    // apply for acceleration
    dot = acceleration.x * floor.x + acceleration.y * floor.y;
    acceleration = floor * dot;
};
