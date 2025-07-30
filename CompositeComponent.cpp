// Copyright 2025 Danny Nguyen
#include "CompositeComponent.hpp"

namespace AP {

CompositeComponent::CompositeComponent(const json& data)
    : Component(data) {
    if (data.contains("children")) {
        for (const auto& child : data["children"]) {
            children_.push_back(Component::fromJson(child));
        }
    }
}

void CompositeComponent::tween(sf::Time time) {
    Component::tween(time);
    for (auto& child : children_) {
        child->tween(time);
    }
}

void CompositeComponent::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (!hasKeyframes()) return;
    KeyFrame frame = currFrame();
    sf::Transform local;
    frame.transform(local);
    states.transform *= local;

    for (const auto& child : children_) {
       window.draw(*child, states);
    }
}

}  // namespace AP

