#include "Penguin.h"

Penguin::Penguin(int number, int age, const std::string& name) : Bird(number, age, name) 
{
}

void Penguin::paint() {
    body_color = "Black";
}

std::string Penguin::getBodyColor() const {
    return body_color;
}

void Penguin::setBodyColor(const std::string& color) {
    body_color = color;
}
