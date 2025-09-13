#include <iostream>
#include <fstream>
#include <stdexcept>
#include <queue>
#include "graph.h"

Graph::Graph(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    fin >> n;
    matrix.assign(n, std::vector<int>(n, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }
}

void Graph::print() {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Graph::reachable(const std::string& out_filename) {
    std::ofstream fout(out_filename);
    if (!fout.is_open()) {
        throw std::runtime_error("Failed to open output file");
    }

    for (size_t start = 0; start < n; start++) {
        std::vector<bool> visited(n, false);
        std::queue<size_t> q;

        visited[start] = true;
        q.push(start);

        fout << "From vertex " << (start + 1) << " reachable: ";

        while (!q.empty()) {
            size_t u = q.front();
            q.pop();
            for (size_t v = 0; v < n; v++) {
                if (matrix[u][v] != 0 && !visited[v]) {
                    visited[v] = true; 
                    q.push(v);
                    fout << v + 1 << " ";
                }
            }
        }
        fout << "\n";
    }
}