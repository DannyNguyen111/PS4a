// Copyright 2025 Danny Nguyen
#include "RectangleComponent.hpp"

namespace AP {

RectangleComponent::RectangleComponent(const json& data):Component(data),
x_(data.value("x", 0.0f)), y_(data.value("y", 0.0f)),
width_(data.value("width", 0.0f)), height_(data.value("height", 0.0f)) {}
void RectangleComponent::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (!hasKeyframes()) return;
    KeyFrame frame = currFrame();
    sf::Transform local;
    frame.transform(local);
    states.transform *= local;

    sf::RectangleShape rect({width_, height_});
    rect.setFillColor(color());
    rect.setPosition(x_, y_);

    window.draw(rect, states);
}

}  // namespace AP

