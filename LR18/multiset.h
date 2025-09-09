#include <iostream>
#include <vector>
#include "node.h"

class Multiset 
{
private:
    Node* root;

    void destroy(Node* node);

public:
    Multiset();
    ~Multiset();

    void insert(int value);
    int find(int value) const; // возвращает количество
    void erase(int value);     // удаляет один экземпляр записи

    friend std::ostream& operator<<(std::ostream& out, const Multiset& item);
};