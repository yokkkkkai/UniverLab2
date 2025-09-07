#include "SortedArray.h"
#include <iostream>

struct Point
{
    int x, y, z;
    bool operator<(const Point &other) const
    {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

void printPoints(const SortedArray<Point>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        Point p = arr[i];
        std::cout << "(" << p.x << "," << p.y << "," << p.z << ") ";
    }
    std::cout << "\n";
}

int main()
{
    SortedArray<int> intArr(5);
    intArr.push(10); intArr.push(5); intArr.push(8);
    intArr.print();
    intArr.erase(1);
    intArr.print();

    SortedArray<double> doubleArr(5);
    doubleArr.push(3.14); doubleArr.push(1.41); doubleArr.push(2.71);
    doubleArr.print();
    doubleArr.erase(0);
    doubleArr.print();

    SortedArray<Point> points(5);
    points.push({1,2,3}); points.push({0,5,1}); points.push({1,1,1});
    printPoints(points);
    points.erase(1);
    printPoints(points);

    Point p0 = points[0];
    Point p1 = points.at(1);
    std::cout << "points[0]=(" << p0.x << "," << p0.y << "," << p0.z << ")\n";
    std::cout << "points.at(1)=(" << p1.x << "," << p1.y << "," << p1.z << ")\n";

    SortedArray<int> a(5);
    a.push(1); a.push(2); a.push(3);

    SortedArray<int> b(5);
    b.push(4); b.push(5);

    std::cout << "A: "; a.print();
    std::cout << "B: "; b.print();
    a + b;
    std::cout << "A + B: "; a.print();

    SortedArray<int> c(5);
    c.push(2); c.push(4);

    std::cout << "A: "; a.print();
    std::cout << "C: "; c.print();
    SortedArray<int> d = a - c;
    std::cout << "A - C: "; d.print();

    return 0;
}
