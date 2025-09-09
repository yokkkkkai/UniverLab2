#include "node.h"

Node::Node(int val)
{
    value.push_back(val);
    left = nullptr;
    right = nullptr;
}