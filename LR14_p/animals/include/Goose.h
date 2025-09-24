#ifndef GOOSE_H
#define GOOSE_H

#include <iostream>
#include <string>
#include "Bird.h"

class Goose : public Bird {
private:
    std::string wing_color;
    std::string paw_color;
    std::string body_color;

public:
    Goose(int number, int age, const std::string& name);

    void paint() override;

    std::string getWingColor() const;
    std::string getPawColor() const;
    std::string getBodyColor() const;

    void setWingColor(const std::string& color);
    void setPawColor(const std::string& color);
    void setBodyColor(const std::string& color);
};

#endif
