#include "constraints.hpp"


void Constraint::apply_constraint() {};


void PositionConstraint::apply_constraint() {
    particle->position = position;
    particle->velocity = sf::Vector2f();
    particle->acceleration = sf::Vector2f();
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
    // TODO : implement 'static collision' (named by me)
};
