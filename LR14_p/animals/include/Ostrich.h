#ifndef OSTRICH_H
#define OSTRICH_H

#include "include/Bird.h"
#include <string>

class Ostrich : public Bird {
private:
    std::string paw_color;
    std::string wing_color;

public:
    Ostrich(int number, int age, const std::string& name);

    void paint() override;

    std::string getPawColor() const;
    std::string getWingColor() const;

    void setPawColor(const std::string& color);
    void setWingColor(const std::string& color);
};

#endif // OSTRICH_H
