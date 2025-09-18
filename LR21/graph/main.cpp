#include "graph.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <comparison_file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string comparisonFile = argv[3];

    Graph myGraph;
    
    if (!myGraph.loadGraph(inputFile)) {
        return 1;
    }

    int startNode = 0;

    myGraph.compareAlgorithms(startNode, comparisonFile);

    Metrics bf_metrics;
    std::vector<int> bf_distances = myGraph.bellmanFord(startNode, bf_metrics);
    myGraph.saveResults(outputFile, "Bellman-Ford", bf_distances, startNode);

    Metrics dijkstra_metrics;
    std::vector<int> dijkstra_distances = myGraph.dijkstra(startNode, dijkstra_metrics);
    myGraph.saveResults(outputFile, "Dijkstra", dijkstra_distances, startNode);

    std::cout << "All results saved to " << outputFile << std::endl;
    std::cout << "Comparison metrics saved to " << comparisonFile << std::endl;

    return 0;
}