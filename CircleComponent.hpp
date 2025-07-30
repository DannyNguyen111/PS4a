// Copyright 2025 Danny Nguyen
#pragma once

#include "Component.hpp"

namespace AP {
class CircleComponent : public Component {
 public:
    explicit CircleComponent(const json& data);
 protected:
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
 private:
    float radius_;
};
}

