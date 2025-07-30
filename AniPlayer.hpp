// Copyright 2025 Danny Nguyen
#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace AP {
class AniPlayer: public sf::Drawable {
 public:
    explicit AniPlayer(const std::string& filename);

    void tween(sf::Time time);  // For part B

    unsigned int pixelWidth() const;
    unsigned int pixelHeight() const;
 protected:
    void draw(sf::RenderTarget& target,
    sf::RenderStates states) const override;
 private:
    unsigned int width_ = 0;
    unsigned int height_ = 0;
    std::unique_ptr<Component> scene_;
};
}  // namespace AP
