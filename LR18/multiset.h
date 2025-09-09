#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
#include <vector>
#include "node.h"

class Multiset 
{
private:
    Node* root;

    void destroy(Node* node);
    Node* minNode(Node* root) const;
    Node* eraseNode(Node* root, int key);

public:
    Multiset();
    ~Multiset();

    void insert(int val);
    int find(int val) const;
    void erase(int val);
    friend std::ostream& operator<<(std::ostream& out, const Multiset& item);

};

void print(std::ostream& out, Node* node);

#endif