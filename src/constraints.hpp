#ifndef CONST_HPP
#define CONST_HPP

#include <vector>// holy grail
#include <cmath>
#include <SFML/Graphics.hpp>
#include "particle.hpp"


class PositionConstraint {
    public:
        sf::Vector2f position;
        Particle * particle;

    void apply_constraint();
};


class PointDistanceConstraint {
    public:
        sf::Vector2f point;
        float distance;
        Particle * particle;

    void apply_constraint();
};

#endif
