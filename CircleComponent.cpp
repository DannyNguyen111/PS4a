// Copyright 2025 Danny Nguyen
#include "CircleComponent.hpp"
#include <iostream>

namespace AP {

CircleComponent::CircleComponent(const json& data)
    : Component(data), radius_(data.value("radius", 10.0f)) {}

void CircleComponent::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (!hasKeyframes()) return;
    KeyFrame frame = currFrame();
    sf::Transform local;
    frame.transform(local);
    states.transform *= local;

    sf::CircleShape circle(radius_);
    circle.setFillColor(color());
    circle.setOrigin(radius_, radius_);
    window.draw(circle, states);
}

}  // namespace AP

