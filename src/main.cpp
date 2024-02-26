#include <iostream>
#include <SFML/Graphics.hpp>

#include "particle.hpp"
#include "constraints.hpp"


struct{
    sf::Vector2f position = sf::Vector2f(0., 0.);
    float zoom = 1.;
} camera;


// pointers are so simple yet so complex...
// wtf is this ? ------------v  a reference to the object ? (yes) but why this notation ?
void update(sf::RenderWindow & window);


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Playground");

    // for cam move
    sf::Vector2i last_mouse_pos(0, 0);
    bool mouse_was_released(true);

    // main loop
    while (window.isOpen()) {

        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                // zoom in / out (mouse wheel)
                case sf::Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.delta == 1) {
                    camera.zoom *= 1.1;
                    } else {
                        camera.zoom /= 1.1;
                    }
            }
        }

    // move cam
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mpos(sf::Mouse::getPosition());
        if (mouse_was_released) {
            mouse_was_released = false;
        } else {
            sf::Vector2f delta(last_mouse_pos - mpos);
            delta.x *= 1. / camera.zoom;
            delta.y *= 1. / camera.zoom;
            camera.position += delta;
        }
        last_mouse_pos = sf::Mouse::getPosition();
    } else {
        mouse_was_released = true;
    }

    // update window
    window.clear();
    update(window);
    window.display();
    }
}


void update(sf::RenderWindow & window) {
    sf::RectangleShape rect(sf::Vector2f(100., 60.));
    rect.setFillColor(sf::Color(204, 64, 134, 200));
    rect.setPosition(10, 100);
    // apply camera
    rect.setScale(camera.zoom, camera.zoom);
    rect.setOrigin(sf::Vector2f(camera.position));
    // draw
    window.draw(rect);
}
