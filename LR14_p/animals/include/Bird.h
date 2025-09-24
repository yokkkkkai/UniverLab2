#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Bird {
private:
    int number;
    int age;
    std::string name;

public:
    Bird(int number, int age, const std::string& name);
    virtual ~Bird() = default;

    virtual void paint() = 0;

    bool operator==(const Bird& other);

    int getNumber() const;
    int getAge() const;
    std::string getName() const;

    void setNumber(int number);
    void setAge(int age);
    void setName(const std::string& name);
};

#endif
