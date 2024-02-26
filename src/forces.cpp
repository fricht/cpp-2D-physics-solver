#include "forces.hpp"


void Force::apply_force(float delta_t) {};


void GravityForce::apply_force(float delta_t) {
    for (Particle * p : * particles) {
        p->acceleration += gravity * delta_t;
    }
};
