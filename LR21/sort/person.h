#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string name;
    int age;
public:
    Person();
    Person(const std::string& n, const int a);

    std::string getName() const;
    int getAge() const;

    bool operator<(const Person& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif