#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int x, int y) {
    return (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 1);
}

bool findPath(vector<vector<int>> &maze, int x, int y, int midX, int midY, vector<vector<int>> &path) {
    if (x == midX && y == midY) {
        path[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y)) {
        path[x][y] = 1;
        if (findPath(maze, x + 1, y, midX, midY, path)) return true;
        if (findPath(maze, x, y + 1, midX, midY, path)) return true;
        path[x][y] = 0;
    }
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};
    int n = maze.size(), m = maze[0].size();
    vector<vector<int>> path(n, vector<int>(m, 0));
    int midX = n / 2, midY = m / 2;

    if (findPath(maze, 0, 0, midX, midY, path)) {
        for (auto row : path) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "No Path Found";
    }
}
// Find Path from Corner Cell to Middle Cell in a Maze