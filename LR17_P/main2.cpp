#include "doublelist.h"
#include <iostream>

int main() {
    DoubleList<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_front(3);

    std::cout << "List A: " << a;

    DoubleList<int> b;
    std::cin >> b;
    std::cout << "List B: " << b;
    DoubleList<int> res_sum = a + b;
    std::cout << "A + B: " << res_sum << std::endl;
    
    int o = 0, n = 0;
    std::cout << "Enter element to replace: ";
    std::cin >> o;
    std::cout << "Enter new value: ";
    std::cin >> n;
    try {
        res_sum.replace(o, n);
        std::cout << "List after replace: " << res_sum << std::endl;
    } catch(std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    DoubleList<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    std::cout << "A: " << l1;

    DoubleList<int> l2;
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    std::cout << "B: " << l2;

    DoubleList<int> result = l1 - l2;
    std::cout << "A - B: " << result << std::endl;

    DoubleList<int> lsort;
    std::cin >> lsort;
    std::cout << "List before sorting: " << lsort;
    lsort.sort();
    std::cout << "List after sorting: " << lsort << std::endl;

    return 0;
}
