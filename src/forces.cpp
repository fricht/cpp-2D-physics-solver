#include "forces.hpp"


void Force::apply_force() {};


void GravityForce::apply_force() {
    for (Particle * p : * particles) {
        p->acceleration += gravity;
    }
};
