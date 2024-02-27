#include "constraints.hpp"


void Constraint::apply_constraint() {};

void Constraint::draw(sf::RenderWindow &, Camera &) {};


void PositionConstraint::apply_constraint() {
    particle->position = position;
    particle->velocity = sf::Vector2f();
};

void PositionConstraint::draw(sf::RenderWindow & window, Camera & camera) {
    sf::RectangleShape pixel(sf::Vector2f(1, 1));
    pixel.setFillColor(sf::Color::Red);
    pixel.setPosition(position);
    camera.apply_cam(pixel);
    window.draw(pixel);
};


void PointDistanceConstraint::apply_constraint() {
    float dx = particle->position.x - point.x;
    float dy = particle->position.y - point.y;
    float dist = std::sqrt(dx * dx + dy * dy);
    sf::Vector2f direction(1, 0); // default vector
    if (dist > 0.) { // ensure no normalizing of null vector (division by 0)
        direction = (particle->position - point) / dist; // normalized
    }
    direction *= distance - dist;
    particle->position += direction;
    // 'static collision' (named by me)
    sf::Vector2f link = point - particle->position;
    sf::Vector2f normal = sf::Vector2f(link.y, -link.x);
    particle->static_collision(normal);
};

void PointDistanceConstraint::draw(sf::RenderWindow & window, Camera & camera) {
    sf::Vertex line[2];
    line[0].position = (point - camera.position) * camera.zoom;
    line[0].color = sf::Color::Green;
    line[1].position = (particle->position - camera.position) * camera.zoom;
    line[1].color = sf::Color::Red;
    window.draw(line, 2, sf::Lines);
};


void FloorConstraint::apply_constraint() {
    for (Particle * p : * particles) {
        if (p->position.y + p->radius > y_pos) {
            p->position.y = y_pos - p->radius;
            // 'static collisions' (easier and manually implemented because parallel to y)
            p->velocity.y = 0.;
        }
    }
};

void FloorConstraint::draw(sf::RenderWindow & window, Camera & camera) {
    float height = (y_pos - camera.position.y) * camera.zoom;
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, height);
    line[0].color = sf::Color::Blue;
    line[1].position = sf::Vector2f(800, height);
    line[1].color = sf::Color::Blue;
    window.draw(line, 2, sf::Lines);
};
