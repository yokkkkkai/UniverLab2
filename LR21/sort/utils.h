#ifndef UTILS_H
#define UTILS_H

#include <list>
#include <string>
#include "person.h"
#include "sorts.h"

std::list<int> readNumbers(const std::string& filename);
void writeNumbers(const std::string& filename, const std::list<int>& data);
std::list<Person> readPeople(const std::string& filename);
void writePeople(const std::string& filename, const std::list<Person>& people);
void writeMetrics(const std::string& filename, const std::string& sortName, const Metrics& metrics);
bool compareInt(const int& a, const int& b);

#endif // UTILS_H