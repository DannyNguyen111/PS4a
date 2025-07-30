// Copyright 2025 Danny Nguyen
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "NullComponent.hpp"
#include "RectangleComponent.hpp"
#include "CircleComponent.hpp"
#include "CompositeComponent.hpp"
#include "ImageComponent.hpp"
#include "TextComponent.hpp"

namespace AP {

Component::Component(const json& data) {
    std::string hex = data.value("color", "FFFFFFFF");
    if (hex.length() == 6) hex += "FF";

    unsigned int r, g, b, a;
    std::stringstream ss;
    ss << std::hex << hex.substr(0, 2);
    ss >> r; ss.clear(); ss.str("");
    ss << std::hex << hex.substr(2, 2);
    ss >> g; ss.clear(); ss.str("");
    ss << std::hex << hex.substr(4, 2);
    ss >> b; ss.clear(); ss.str("");
    ss << std::hex << hex.substr(6, 2);
    ss >> a;
    color_ = sf::Color(r, g, b, a);

    if (data.contains("keyframes")) {
        for (const auto& kf : data["keyframes"]) {
            keyframes_.emplace_back(kf);
        }
    }
}

sf::Color Component::color() const {
    return color_;
}

void Component::tween(sf::Time) {
    // No-op for now (Part B)
}

KeyFrame Component::currFrame() const {
    return keyframes_.empty() ? KeyFrame() : keyframes_.front();
}

std::unique_ptr<Component> Component::fromJson(const json& data) {
    std::string type = data.value("shape", "");

    if (type == "circle") return std::make_unique<CircleComponent>(data);
    if (type == "rectangle" || type == "rect") return std::make_unique<RectangleComponent>(data);
    if (type == "composite") return std::make_unique<CompositeComponent>(data);
    if (type == "image") return std::make_unique<ImageComponent>(data);
    if (type == "text") return std::make_unique<TextComponent>(data);

    throw std::runtime_error("Unknown component shape: " + type);
}

bool Component::hasKeyframes() const {
    return !keyframes_.empty();
}


}  // namespace AP

