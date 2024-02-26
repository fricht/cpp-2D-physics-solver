#ifndef CONST_HPP
#define CONST_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include "particle.hpp"


class Constraint {
    public:

    // intended to be overidden by chindrens
    void apply_constraint();
};


class PositionConstraint : public Constraint {
    public:
        sf::Vector2f position;
        Particle * particle;

    void apply_constraint();
};


class PointDistanceConstraint : public Constraint {
    public:
        sf::Vector2f point;
        float distance;
        Particle * particle;

    void apply_constraint();
};


#endif
