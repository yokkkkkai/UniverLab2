#include "doublelist.h"
#include <iostream>
#include <exception>

struct Point {
    int x, y, z;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

int main() {
    DoubleList<int> d_i;
    d_i.push_back(1);
    d_i.push_back(2);
    d_i.push_back(33);
    std::cout << "Int list: ";
    d_i.print();
    std::cout << "Push front: ";
    d_i.push_front(0);
    d_i.print();
    std::cout << "Size: " << d_i.size() << std::endl;
    std::cout << "Element at index 2: " << d_i.at(2) << std::endl;
    d_i.find_and_erase(33);
    std::cout << "After erase: ";
    d_i.print();

    DoubleList<double> d_d;
    d_d.push_back(1.1);
    d_d.push_back(2.2);
    d_d.push_front(0.5);
    std::cout << "\nDouble list: ";
    d_d.print();
    std::cout << "Size: " << d_d.size() << std::endl;
    std::cout << "Element at index 1: " << d_d.at(1) << std::endl;
    d_d.find_and_erase(1.1);
    std::cout << "After erase 1.1: ";
    d_d.print();

    DoubleList<Point> d_p;
    d_p.push_back({1, 2, 3});
    d_p.push_back({4, 5, 6});
    d_p.push_front({0, 0, 0});
    std::cout << "\nPoint list: ";
    d_p.print();
    std::cout << "Size: " << d_p.size() << std::endl;
    Point p = d_p.at(1);
    std::cout << "Element at index 1: " << p << std::endl;
    d_p.find_and_erase({4, 5, 6});
    std::cout << "After erase (4,5,6): ";
    d_p.print();

    std::cout << "Try erase 8 in int list: " << std::endl;
    try {
        d_i.find_and_erase(8);
    } catch (std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}