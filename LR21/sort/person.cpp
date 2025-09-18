#include "person.h"
#include <iostream>

Person::Person() : name(""), age(0) {}
Person::Person(const std::string& n, const int a) : name(n), age(a) {}

bool Person::operator<(const Person& other) const
{
    return age < other.age;
}

std::string Person::getName() const
{
    return name;
}

int Person::getAge() const 
{
    return age;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << " (" << (int)p.age << ")";
    return os;
}