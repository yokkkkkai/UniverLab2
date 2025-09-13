/*
Во всех заданиях необходимо реализовать программу на языке C/C++. 
В исходном файле содержится описание графа (способ хранения описан в задании). 
Программа выводит результат своей работы в текстовый файл.

Ориентированный граф задан и хранится матрицей смежности. 
Для каждой вершины графа выписать список вершин, достижимых из нее (не только соседние вершины).
*/

#include "graph.h"
#include <stdexcept>
#include <iostream>

int main() {
    try {
        Graph g("m.txt");
        g.reachable_bfs("result_bfs.txt");
        g.reachable_dfs("result_dfs.txt");
    } catch (const std::runtime_error& e) {
        std::cout << "Error! " << e.what() << std::endl;
    }
    return 0;
}