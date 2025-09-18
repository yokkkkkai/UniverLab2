#include "mergesort.h"
#include "person.h"
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

/*
Во всех заданиях необходимо реализовать 2 программы на полный балл и 1 программу на половину баллов на языке C/C++. 
Во всех заданиях входные данные (массивы для сортировки; описание графа; стартовая вершина) 
хранятся во входном текстовом файле, выходные данные (отсортированные массивы; длины путей; пути; точки сочленения) хранятся в выходном текстовом файле.

Реализовать сортировку слиянием в стиле обобщенного программирования (шаблоны). 
В main должны быть отсортированы массив целых числе int и массив классов Person (имя, возраст). 
Реализовать алгоритм Беллмана-Форда для поиска кратчайших путей в графе, представленного списком смежности. 
Выписать длины кратчайших путей.

*/

//Реализовать сортировку пузырьком и какую-нибудь еще и сравнить по эффективности
//Сортировка по параметрам на выбор пользователя

template <typename T>
void printContainer(const T& container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void readInt(const std::string& filename, std::vector<int>& vec) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return;
    }
    int number;
    while (file >> number) {
        vec.push_back(number);
    }
    file.close();
}

void writeInt(const std::string& filename, const std::vector<int>& vec) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи " << filename << std::endl;
        return;
    }
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        file << *it << " ";
    }
    file.close();
}

void readPerson(const std::string& filename, std::list<Person>& people) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error! File is not open! " << filename << std::endl;
        return;
    }
    std::string name;
    int age;
    while (file >> name >> age) {
        people.emplace_back(name, age);
    }
    file.close();
}

void writePerson(const std::string& filename, const std::list<Person>& people) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error file is not open! " << filename << std::endl;
        return;
    }
    for (std::list<Person>::const_iterator it = people.begin(); it != people.end(); ++it) {
        file << it->getName() << " " << it->getAge() << std::endl;
    }
    file.close();
}

int main() {
    std::vector<int> numbers;
    readInt("array.txt", numbers);
    mergeSort(numbers.begin(), numbers.end());
    writeInt("result_array.txt", numbers);

    std::list<Person> people;
    readPerson("person.txt", people);
    mergeSort(people.begin(), people.end());
    writePerson("result_person.txt", people);

    return 0;
}