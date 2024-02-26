#ifndef PART_HPP
#define PART_HPP

#include <SFML/Graphics.hpp>
#include "camera.hpp"


class Particle {
    public:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        float mass;
        float radius;
        sf::Color color;

    void simulate(float);

    void draw(sf::RenderWindow &, Camera &);
};


#endif
