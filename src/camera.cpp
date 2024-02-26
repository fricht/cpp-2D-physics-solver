#include "camera.hpp"


void Camera::apply_cam(sf::Shape & shape) {
    shape.setOrigin(position);
    shape.setScale(zoom, zoom);
};
