#include "include/Bird.h"

Bird::Bird(int number, int age, const std::string& name)
    : number(number), age(age), name(name) {}

bool Bird::operator==(const Bird& other) {
    return (number == other.number) && (age == other.age) && (name == other.name);
}

int Bird::getNumber() const {
    return number;
}

int Bird::getAge() const {
    return age;
}

std::string Bird::getName() const {
    return name;
}

void Bird::setNumber(int number) {
    this->number = number;
}

void Bird::setAge(int age) {
    this->age = age;
}

void Bird::setName(const std::string& name) {
    this->name = name;
}