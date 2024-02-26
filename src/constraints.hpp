#ifndef CONST_HPP
#define CONST_HPP

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "particle.hpp"


class Constraint {
    public:

    // intended to be overidden by chindrens
    virtual void apply_constraint();
    virtual void draw(sf::RenderWindow &, void *);
};


class PositionConstraint : public Constraint {
    public:
        sf::Vector2f position;
        Particle * particle;

    void apply_constraint();
    void draw(sf::RenderWindow &, void *);
};


class PointDistanceConstraint : public Constraint {
    public:
        sf::Vector2f point;
        float distance;
        Particle * particle;

    void apply_constraint();
    void draw(sf::RenderWindow &, void *);
};


class FloorConstraint : public Constraint {
    public:
        float y_pos;
        std::vector<Particle *> * particles;

    void apply_constraint();
    void draw(sf::RenderWindow &, void *);
};


#endif
