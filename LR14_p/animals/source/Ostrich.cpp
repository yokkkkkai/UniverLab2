#include "include/Ostrich.h"

Ostrich::Ostrich(int number, int age, const std::string& name) 
    : Bird(number, age, name) {}
    
void Ostrich::paint() {
    paw_color = wing_color;
}

std::string Ostrich::getPawColor() const {
    return paw_color;
}

std::string Ostrich::getWingColor() const {
    return wing_color;
}

void Ostrich::setPawColor(const std::string& color) {
    paw_color = color;
}

void Ostrich::setWingColor(const std::string& color) {
    wing_color = color;
}
