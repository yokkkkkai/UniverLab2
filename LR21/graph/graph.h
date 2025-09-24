#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

struct Metrics 
{
    size_t total_operations = 0;
    size_t distance_updates = 0;
};

class Graph {
private:
    int vertexCount;
    
    struct Edge {
        int start;
        int end;
        int cost;
    };
    std::vector<Edge> edges;

public:
    Graph();
    
    bool loadGraph(const std::string& fileName);
    void saveResults(const std::string& fileName, const std::string& algorithmName, const std::vector<int>& distances, int init);
    void compareAlgorithms(int startVertex, const std::string& outputFile);
    
    std::vector<int> bellmanFord(int init, Metrics& metrics);
    std::vector<int> dijkstra(int init, Metrics& metrics);
};

#endif