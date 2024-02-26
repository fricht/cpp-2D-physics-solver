#include <iostream>
#include <SFML/Graphics.hpp>

#include "particle.hpp"
#include "forces.hpp"
#include "constraints.hpp"


struct {
    sf::Vector2f position = sf::Vector2f(0., 0.);
    float zoom = 1.;
} camera;


class Scene {
    public:
        std::vector<Particle *> particles;
        std::vector<Force *> forces;
        std::vector<Constraint *> constraints;

    void update(float, uint);

    void draw(sf::RenderWindow & window);
};

void Scene::update(float delta_t, uint iterations) {
    for (Force * f : forces) {
        f->apply_force(delta_t);
    }
    for (Particle * p : particles) {
        p->simulate(delta_t);
    }
    for (uint i = 0; i < iterations; i++) {
        for (Constraint * c : constraints) {
            c->apply_constraint();
        }
    }
}

void Scene::draw(sf::RenderWindow & window) {
    for (Particle * p : particles) {
        sf::CircleShape p_shape(p->radius);
        p_shape.setFillColor(p->color);
        p_shape.setPosition(p->position);
        // apply cam
        p_shape.setScale(camera.zoom, camera.zoom);
        p_shape.setOrigin(camera.position);
        window.draw(p_shape);
    }
}


// pointers are so simple yet so complex...
// wtf is this ? ------------v  a reference to the object ? (yes) but why this notation ?
void update(sf::RenderWindow &, Scene &, float);


void generate_scene(Scene &);


int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Playground");

    // for cam move
    sf::Vector2i last_mouse_pos(0, 0);
    bool mouse_was_released(true);

    // scene
    Scene scene{};
    generate_scene(scene);

    // delta time
    sf::Clock delta_clock;

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
    update(window, scene, delta_clock.restart().asSeconds());
    window.display();
    }
};


void update(sf::RenderWindow & window, Scene & scene, float delta_t) {
    // physics update
    scene.update(delta_t, 4);
    // render
    scene.draw(window);
};


void generate_scene(Scene & scene) {
    Particle * p;
    // free fall particle
    p = new Particle;
    p->color = sf::Color(255, 255, 255);
    p->radius = 10;
    p->position = sf::Vector2f(100, 100);
    p->acceleration = sf::Vector2f(15, 8);
    scene.particles.push_back(p);
    // pendulum particle
    p = new Particle;
    p->color = sf::Color(255, 0, 0);
    p->radius = 8;
    p->position = sf::Vector2f(200, 100);
    scene.particles.push_back(p);
    // pendulum
    PointDistanceConstraint * pendulum = new PointDistanceConstraint;
    pendulum->distance = 50;
    pendulum->point = sf::Vector2f(250, 100);
    pendulum->particle = p;
    scene.constraints.push_back(pendulum);
    // floor
    FloorConstraint * floor = new FloorConstraint;
    floor->particles = & scene.particles;
    floor->y_pos = 300;
    scene.constraints.push_back(floor);
    // gravity
    GravityForce * gravity = new GravityForce;
    gravity->particles = & scene.particles;
    gravity->gravity = sf::Vector2f(0, 9.9);
    scene.forces.push_back(gravity);
};
