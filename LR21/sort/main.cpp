#include <iostream>
#include <list>
#include <string>
#include "person.h"
#include "sorts.h"
#include "utils.h"

int getSortChoice() {
    int choice;
    while (true) {
        std::cout << "Select a sorting criterion for the Person list (1 - age, 2 - name): ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) {
            break;
        }
        std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
    }
    return choice;
}

int main() {
    std::list<int> numbers = readNumbers("input/numbers.txt");

    std::list<int> copy1 = numbers;
    Metrics m1;
    mergeSort(copy1.begin(), copy1.end(), m1, compareInt);
    writeNumbers("output/merge_numbers.txt", copy1);
    writeMetrics("output/metrics.txt", "MergeSort (int)", m1);

    std::list<int> copy2 = numbers;
    Metrics m2;
    bubbleSort(copy2.begin(), copy2.end(), m2, compareInt);
    writeNumbers("output/bubble_numbers.txt", copy2);
    writeMetrics("output/metrics.txt", "BubbleSort (int)", m2);

    std::list<int> copy3 = numbers;
    Metrics m3;
    insertionSort(copy3.begin(), copy3.end(), m3, compareInt);
    writeNumbers("output/insertion_numbers.txt", copy3);
    writeMetrics("output/metrics.txt", "InsertionSort (int)", m3);

    std::list<Person> people = readPeople("input/person.txt");

    std::cout << "\nSorting the Person class: " << std::endl;
    int choice = getSortChoice();
    auto compareFunc = (choice == 1) ? compareByAge : compareByName;
    std::string criterion = (choice == 1) ? "age" : "name";

    std::list<Person> p1 = people;
    Metrics pm1;
    mergeSort(p1.begin(), p1.end(), pm1, compareFunc);
    writePeople("output/merge_people_" + criterion + ".txt", p1);
    writeMetrics("output/metrics.txt", "MergeSort (Person, " + criterion + ")", pm1);

    std::list<Person> p2 = people;
    Metrics pm2;
    bubbleSort(p2.begin(), p2.end(), pm2, compareFunc);
    writePeople("output/bubble_people_" + criterion + ".txt", p2);
    writeMetrics("output/metrics.txt", "BubbleSort (Person, " + criterion + ")", pm2);

    std::list<Person> p3 = people;
    Metrics pm3;
    insertionSort(p3.begin(), p3.end(), pm3, compareFunc);
    writePeople("output/insertion_people_" + criterion + ".txt", p3);
    writeMetrics("output/metrics.txt", "InsertionSort (Person, " + criterion + ")", pm3);
    return 0;
}