// Copyright 2025 Danny Nguyen
#include "KeyFrame.hpp"

namespace AP {

KeyFrame::KeyFrame() : time_(0), x_(0), y_(0), scaleX_(1), scaleY_(1), theta_(0) {}

KeyFrame::KeyFrame(const json& data):time_(data.at("t").get<float>()),
x_(data.value("x", 0.0f)), y_(data.value("y", 0.0f)),
 scaleX_(data.value("scale-x", 1.0f)), scaleY_(data.value("scale-y", 1.0f)),
theta_(data.value("theta", 0.0f)) {}
float KeyFrame::time() const {
    return time_;
}

void KeyFrame::transform(sf::Transform& state) const {
    state.translate(x_, y_);
    state.rotate(theta_);
    state.scale(scaleX_, scaleY_);
}

}  // namespace AP

