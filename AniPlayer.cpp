// Copyright 2025 Danny Nguyen
#include "AniPlayer.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace AP {

AniPlayer::AniPlayer(const std::string& filename) {
    std::ifstream ifs(filename);
    json data;
    ifs >> data;

    width_ = data["width"];
    height_ = data["height"];
    if (data.contains("scene")) {
        scene_ = Component::fromJson(data["scene"]);
    } else {
        scene_ = nullptr;
    }
}

void AniPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (scene_) {
        target.draw(*scene_, states);
    }
}

unsigned int AniPlayer::pixelWidth() const {
    return width_;
}

unsigned int AniPlayer::pixelHeight() const {
    return height_;
}

void AniPlayer::tween(sf::Time) {
    // For Part B
}

}  // namespace AP

