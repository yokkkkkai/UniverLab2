#include "include/Goose.h"

Goose::Goose(int number, int age, const std::string& name)
    : Bird(number, age, name) {}

void Goose::paint() {
    wing_color = "Grey";
    paw_color = "Yellow";
    body_color = "White";
}

std::string Goose::getWingColor() const {
    return wing_color;
}

std::string Goose::getPawColor() const {
    return paw_color;
}

std::string Goose::getBodyColor() const {
    return body_color;
}

void Goose::setWingColor(const std::string& color) {
    wing_color = color;
}

void Goose::setPawColor(const std::string& color) {
    paw_color = color;
}

void Goose::setBodyColor(const std::string& color) {
    body_color = color;
}
