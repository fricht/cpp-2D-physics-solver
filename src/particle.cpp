#include "particle.hpp"


void Particle::simulate(float delta_t) {
    velocity += acceleration * delta_t;
    position += velocity * delta_t;
    acceleration = sf::Vector2f(0, 0);
};


void Particle::draw(sf::RenderWindow & window, Camera & camera) {
    sf::CircleShape p_shape(radius);
    p_shape.setFillColor(color);
    p_shape.setPosition(position - sf::Vector2f(radius, radius));
    // apply cam
    camera.apply_cam(p_shape);
    window.draw(p_shape);
};


void Particle::draw_vectors(sf::RenderWindow & window, Camera & camera) {
    // draw velocity
    sf::Vertex line[2];
    line[0].position = (position - camera.position) * camera.zoom;
    line[0].color = sf::Color::White;
    line[1].position = (position + velocity - camera.position) * camera.zoom;
    line[1].color = sf::Color::Blue;
    window.draw(line, 2, sf::Lines);
    // draw acceleration
    line[0].position = (position - camera.position) * camera.zoom;
    line[0].color = sf::Color::White;
    line[1].position = (position + acceleration - camera.position) * camera.zoom;
    line[1].color = sf::Color::Red;
    window.draw(line, 2, sf::Lines);
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
};
