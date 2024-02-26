#include "particle.hpp"


void Particle::simulate(float delta_t) {
    velocity += acceleration * delta_t;
    position += velocity * delta_t;
};


void Particle::draw(sf::RenderWindow & window, Camera & camera) {
    sf::CircleShape p_shape(radius);
    p_shape.setFillColor(color);
    p_shape.setPosition(position);
    // apply cam
    camera.apply_cam(p_shape);
    window.draw(p_shape);
};
