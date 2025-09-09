#include <vector>

struct Node
{
    std::vector<int> value;
    Node* left;
    Node* right;

    Node(int val);
};