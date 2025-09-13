#include <vector>
#include <string>

class Graph {
private:
    size_t n;
    std::vector<std::vector<int>> matrix;
public:
    Graph(const std::string& filename);
    void print();
    void reachable_bfs(const std::string& out_filename);
    void reachable_dfs(const std::string& out_filename);

private:
    void dfs(size_t v, std::vector<bool>& visited, std::ofstream& fout, bool isStart = false);
};