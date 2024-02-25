#include "particle.hpp"


void Particle::simulate(float delta_t) {
    velocity += acceleration * delta_t;
    position += velocity * delta_t;
};
