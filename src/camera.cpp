#include "camera.hpp"


void Camera::apply_cam(sf::Shape & shape) {
    shape.setScale(zoom, zoom);
    shape.setOrigin(position);
    shape.setPosition(shape.getPosition() * zoom);
};
