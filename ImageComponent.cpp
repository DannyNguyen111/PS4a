// Copyright 2025 Danny Nguyen
#include <stdexcept>
#include "ImageComponent.hpp"
namespace AP {

ImageComponent::ImageComponent(const json& data)
    : Component(data) {
    std::string path = data.at("file").get<std::string>();
    if (!texture_.loadFromFile(path)) {
        throw std::runtime_error("Could not load image: " + path);
    }
    sprite_.setTexture(texture_);
    sprite_.setOrigin(texture_.getSize().x / 2.0f, texture_.getSize().y / 2.0f);
}

void ImageComponent::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (!hasKeyframes()) return;
    KeyFrame frame = currFrame();
    sf::Transform local;
    frame.transform(local);
    states.transform *= local;

    sf::Sprite s = sprite_;
    s.setColor(color());

    window.draw(s, states);
}

}  // namespace AP

