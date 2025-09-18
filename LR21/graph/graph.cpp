#include "graph.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
#include <vector>

Graph::Graph() : vertexCount(0) {}

bool Graph::loadGraph(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "File could not be opened: " << fileName << std::endl;
        return false;
    }

    file >> vertexCount;
    edges.clear();

    int u, v, w;
    while (file >> u >> v >> w) {
        edges.push_back({u, v, w});
    }

    file.close();
    return true;
}

void Graph::saveResults(const std::string& fileName, const std::string& algorithmName, const std::vector<int>& distances, int init) {
    std::ofstream file(fileName, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "File could not be opened for writing: " << fileName << std::endl;
        return;
    }

    static bool first_call = true;
    if (!first_call) {
        file << "\n----------------------------------------\n\n";
    }
    first_call = false;

    file << "Algorithm: " << algorithmName << "\n";
    file << "Paths from starting node " << init << ":\n";
    for (int i = 0; i < static_cast<int>(distances.size()); ++i) {
        file << "Node " << i << ": " << (distances[i] == std::numeric_limits<int>::max() ? "unreachable" : std::to_string(distances[i])) << "\n";
    }
    file.close();
}

std::vector<int> Graph::bellmanFord(int init, Metrics& metrics) {
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> distances(vertexCount, INF);
    distances[init] = 0;
    metrics.total_operations++;

    for (int i = 0; i < vertexCount - 1; ++i) {
        for (const auto& edge : edges) {
            metrics.total_operations++;
            if (distances[edge.start] != INF && distances[edge.start] + edge.cost < distances[edge.end]) {
                distances[edge.end] = distances[edge.start] + edge.cost;
                metrics.distance_updates++;
            }
        }
    }

    for (const auto& edge : edges) {
        metrics.total_operations++;
        if (distances[edge.start] != INF && distances[edge.start] + edge.cost < distances[edge.end]) {
            distances[edge.end] = distances[edge.start] + edge.cost;
            metrics.distance_updates++;
        }
    }

    return distances;
}

std::vector<int> Graph::dijkstra(int init, Metrics& metrics) {
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> distances(vertexCount, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    distances[init] = 0;
    pq.push({0, init});
    metrics.total_operations += 2;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        metrics.total_operations++;

        if (d > distances[u]) continue;

        for (const auto& edge : edges) {
            if (edge.start == u) {
                int v = edge.end;
                int w = edge.cost;
                metrics.total_operations++;
                if (distances[u] != INF && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                    pq.push({distances[v], v});
                    metrics.distance_updates++;
                    metrics.total_operations++;
                }
            }
        }
    }

    return distances;
}

void Graph::compareAlgorithms(int startVertex, const std::string& outputFile) {
    Metrics bf_metrics, dijkstra_metrics;
    
    std::vector<int> bf_dist = bellmanFord(startVertex, bf_metrics);
    std::vector<int> dijkstra_dist = dijkstra(startVertex, dijkstra_metrics);
    
    std::ofstream file(outputFile);
    file << "BELLMAN-FORD:\n";
    file << "  Total operations: " << bf_metrics.total_operations << "\n";
    file << "  Distance updates: " << bf_metrics.distance_updates << "\n\n";
    
    file << "DIJKSTRA:\n";
    file << "  Total operations: " << dijkstra_metrics.total_operations << "\n";
    file << "  Distance updates: " << dijkstra_metrics.distance_updates << "\n\n";
    
    file.close();
}