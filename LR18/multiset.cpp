#include "multiset.h"

void Multiset::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

Multiset::Multiset()
{
    root = nullptr;
}

Multiset::~Multiset()
{
    destroy(root);
}

void Multiset::insert(int val)
{
    if(!root)
    {
        root = new Node(val);
        return;
    }

    Node* current = root;

    while(true)
    {
        if(val < current->value[0])
        {
            if(current->left = nullptr)
            {
                current->left = new Node(val);
                break;
            }
            else 
            {
                current = current->left;
            }
        }
        else if(val > current->value[0])
        {
            if(current->right == nullptr)
            {
                current->right = new Node(val);
                break;
            }
            else 
            {
                current = current->right;
                break;
            }
        }
        else
        {
            current->value.push_back(val);
            break;
        }
    }


}