#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int x, int y) {
    return (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 1);
}

bool solveMazeUtil(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol) {
    if (x == maze.size() - 1 && y == maze[0].size() - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, sol)) return true;
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;
        sol[x][y] = 0;
    }
    return false;
}

void solveMaze(vector<vector<int>> &maze) {
    vector<vector<int>> sol(maze.size(), vector<int>(maze[0].size(), 0));
    if (solveMazeUtil(maze, 0, 0, sol)) {
        for (auto &row : sol) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "No Solution";
    }
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {0, 1, 0, 0},
                                {1, 1, 1, 1}};
    solveMaze(maze);
}
// Rat in a Maze