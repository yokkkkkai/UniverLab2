#include "utils.h"
#include <fstream>
#include <iostream>

std::list<int> readNumbers(const std::string& filename) {
    std::list<int> numbers;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening " << filename << std::endl;
        return numbers;
    }
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

void writeNumbers(const std::string& filename, const std::list<int>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error writing " << filename << std::endl;
        return;
    }
    for (int num : data) {
        file << num << "\n";
    }
}

std::list<Person> readPeople(const std::string& filename) {
    std::list<Person> people;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening " << filename << std::endl;
        return people;
    }
    std::string name;
    int age;
    while (file >> name >> age) {
        people.push_back(Person(name, age));
    }
    return people;
}

void writePeople(const std::string& filename, const std::list<Person>& people) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error writing " << filename << std::endl;
        return;
    }
    for (const Person& p : people) {
        file << p.getName() << " " << p.getAge() << std::endl;
    }
}

void writeMetrics(const std::string& filename, const std::string& sortName, const Metrics& metrics) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error writing " << filename << std::endl;
        return;
    }
    file << sortName
         << " | Comparisons: " << metrics.comparisons
         << " | Swaps: " << metrics.swaps
         << " | Passes: " << metrics.passes
         << std::endl;
}

bool compareInt(const int& a, const int& b) {
    return a < b;
}

bool compareByName(const Person& a, const Person& b) {
    return a.getName() < b.getName();
}

bool compareByAge(const Person& a, const Person& b) {
    return a.getAge() < b.getAge();
}