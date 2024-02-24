#include <iostream>
#include <SFML/Graphics.hpp>


void update(sf::RenderWindow &window) {
    sf::RectangleShape rect(sf::Vector2f(100., 60.));
    rect.setFillColor(sf::Color(12, 12, 134, 50));
    rect.setPosition(10, 100);
    window.draw(rect);
}


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Playground");

    // main loop
    while (window.isOpen()) {

        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
            }
        }

    // update window
    window.clear();
    update(window);
    window.display();
    }
}
