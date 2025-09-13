#include <vector>
#include <string>

class Graph {
private:
    size_t n;
    std::vector<std::vector<int>> matrix;
public:
    Graph(const std::string& filename);
    void print();
    void reachable(const std::string& out_filename);

};