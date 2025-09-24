#ifndef PENGUIN_H
#define PENGUIN_H

#include "include/Bird.h"
#include <string>

class Penguin : public Bird {
private:
    std::string body_color;

public:
    Penguin(int number, int age, const std::string& name);

    void paint() override;

    std::string getBodyColor() const;
    void setBodyColor(const std::string& color);
};

#endif // PENGUIN_H
