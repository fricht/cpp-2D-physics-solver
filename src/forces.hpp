#ifndef FORCE_HPP
#define FORCE_HPP

#include <vector>
#include "particle.hpp"


class Force {
    public:

    virtual void apply_force();
};


class GravityForce : public Force {
    public:
        sf::Vector2f gravity;
        std::vector<Particle *> * particles;

    void apply_force();
};


#endif
