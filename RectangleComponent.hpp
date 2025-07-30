// Copyright 2025 Danny Nguyen
#pragma once

#include "Component.hpp"

namespace AP {

class RectangleComponent : public Component {
 public:
    explicit RectangleComponent(const json& data);

 protected:
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

 private:
    float x_, y_, width_, height_;
};

}  // namespace AP

