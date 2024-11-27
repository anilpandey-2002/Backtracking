#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y) {
    return (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && mat[x][y] == 1 && !visited[x][y]);
}

void findLongestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y, int destX, int destY, int &maxDist, int dist) {
    if (x == destX && y == destY) {
        maxDist = max(maxDist, dist);
        return;
    }

    visited[x][y] = true;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isSafe(mat, visited, nx, ny)) {
            findLongestPath(mat, visited, nx, ny, destX, destY, maxDist, dist + 1);
        }
    }

    visited[x][y] = false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}};
    int startX = 0, startY = 0, destX = 3, destY = 4;
    vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
    int maxDist = -1;
    findLongestPath(mat, visited, startX, startY, destX, destY, maxDist, 0);
    cout << (maxDist == -1 ? "No Path" : to_string(maxDist));
}
// Longest Possible Route in a Matrix with Hurdles