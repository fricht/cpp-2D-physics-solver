#ifndef FORCE_HPP
#define FORCE_HPP

#include <vector>
#include "particle.hpp"


class Force {
    public:

    void apply_force(float);
};


class Gravity : public Force {
    public:
        sf::Vector2f gravity;
        std::vector<Particle *> * particles;

    void apply_force(float);
};


#endif
