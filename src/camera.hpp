#ifndef CAM_HPP
#define CAM_HPP

#include <SFML/Graphics.hpp>


struct Camera {
    sf::Vector2f position;
    float zoom = 1.;

    void apply_cam(sf::Shape &);
};


#endif
