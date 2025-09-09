#include "multiset.h"

int main()
{
    Multiset a;
    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(30);
    std::cout << a << std::endl;
    a.erase(10);
    std::cout << a << std::endl;
    a.erase(30);
    std::cout << a << std::endl;
    for(int i = 0; i < 5; i++)
    {
        a.insert(10);
    }
    std::cout << a << std::endl;
    std::cout << a.find(10) << std::endl;
    return 0;
}