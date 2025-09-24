#include "doublelist.h"
#include "include/Bird.h"

class Farm {
private:
    DoubleList<Bird*> array;
public:
    void addAnimal(Bird* animal) {
        array.push_back(animal);
    }
    void deleteAnimal(Bird* animal) {
        array.find_and_erase(animal);
    }

    void show() {
        std::cout << array;
    }
};