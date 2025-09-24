#include "Farm.h"
#include "animals.h"

int main() {
    Farm ex;
    ex.addAnimal(new Goose(1, 2, "Hello"));
    ex.deleteAnimal(new Goose(1, 2, "Hello"));
    ex.show();

    return 0;
}