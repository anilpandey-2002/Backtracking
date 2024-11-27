#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool pathMoreThanK(int src, int k, vector<vector<pair<int, int>>> &graph, vector<bool> &visited) {
    if (k <= 0) return true;
    visited[src] = true;

    for (auto &[v, weight] : graph[src]) {
        if (!visited[v]) {
            if (pathMoreThanK(v, k - weight, graph, visited)) return true;
        }
    }
    visited[src] = false;
    return false;
}

int main() {
    int V = 9, k = 58;
    vector<vector<pair<int, int>>> graph(V);
    graph[0] = {{1, 4}, {7, 8}};
    graph[1] = {{0, 4}, {2, 8}, {7, 11}};
    graph[2] = {{1, 8}, {3, 7}, {5, 4}, {8, 2}};
    graph[3] = {{2, 7}, {4, 9}, {5, 14}};
    graph[4] = {{3, 9}, {5, 10}};
    graph[5] = {{2, 4}, {3, 14}, {4, 10}, {6, 2}};
    graph[6] = {{5, 2}, {7, 1}, {8, 6}};
    graph[7] = {{0, 8}, {1, 11}, {6, 1}, {8, 7}};
    graph[8] = {{2, 2}, {6, 6}, {7, 7}};

    vector<bool> visited(V, false);
    cout << (pathMoreThanK(0, k, graph, visited) ? "Yes" : "No");
}
//  Find if There is a Path of More than k Length from a Source