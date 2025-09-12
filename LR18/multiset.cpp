#include "multiset.h"
#include <queue>

void Multiset::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

Node* Multiset::minNode(Node* root) const
{
    while(root->left != nullptr)
        root = root->left;
    return root;
}

Node* Multiset::eraseNode(Node* root, int key) {
    if(root == nullptr) return nullptr;
    
    if(key < root->value[0])
        root->left = eraseNode(root->left, key);
    else if(key > root->value[0])
        root->right = eraseNode(root->right, key);
    else {
        if(root->value.size() > 1) {
            root->value.pop_back();
            return root;
        }
        
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 

        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = minNode(root->right);
        
        root->value.clear();
        root->value.push_back(temp->value[0]);

        root->right = eraseNode(root->right, temp->value[0]);
    }
    return root;
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
            if(current->left == nullptr)
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
            }
        }
        else
        {
            current->value.push_back(val);
            break;
        }
    }
}

int Multiset::find(int val) const
{
    if(!root)
    {
        return 0;
    }
    
    Node* current = root;
    
    while(current != nullptr)
    {
        if(val < current->value[0])
        {
            current = current->left;
        }
        else if(val > current->value[0])
        {
            current = current->right;
        }
        else
        {
            return current->value.size();
        }
    }
    
    return 0;
}

void Multiset::erase(int val) {
    root = eraseNode(root, val);
}

void print(std::ostream& out, Node* node)
{
    if(node != nullptr)
    {
        print(out, node->left);

        for(int i = 0; i < node->value.size(); i++)
        {
                out << node->value[i] << " ";
        }

        print(out, node->right);
    }
}

void printTree(std::ostream& out, Node* node, int level = 0) {
    if (node == nullptr) {
        return;
    }
    printTree(out, node->right, level + 1);

    for (int i = 0; i < level; ++i) {
        out << "\t";
    }
    
    out << node->value[0] << std::endl;

    printTree(out, node->left, level + 1);
}

std::ostream& operator<<(std::ostream& out, const Multiset& item)
{
    printTree(out, item.root);

    return out;
}

std::istream& operator>>(std::istream& in, Multiset& item)
{
    std::cout << "Enter nums(0 - end): " << std::endl;
    int val = 1;
    while(in >> val && val != 0 && val != EOF)
    {
        item.insert(val);
    }

    return in;
}

/*
Во всех лабораторных работах требуется использовать контейнеры STL.

Реализовать multiset.
void insert(int value)
int find(int value) //возвращает количество 
void erase(int value) //удаляет один экземпляр записи
operator<< для вывода на экран
*/

//operator>>
//графический вывод