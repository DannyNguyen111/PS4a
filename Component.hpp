// Copyright 2025 Danny Nguyen
#pragma once

#include <memory>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "KeyFrame.hpp"

namespace AP {
class Component: public sf::Drawable {
 public:
    virtual void tween(sf::Time time);  // For part B

    static std::unique_ptr<Component> fromJson(const json& json);
 protected:
    explicit Component(const json& json);  // Abstract class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    KeyFrame currFrame() const;  // For part B
    bool hasKeyframes() const;
    sf::Color color() const;
 private:
  sf::Color color_;
  std::vector<KeyFrame> keyframes_;
};
}  // namespace AP
