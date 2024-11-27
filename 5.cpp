#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &mat) {
    return x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && mat[x][y] == 1;
}

void markUnsafeCells(vector<vector<int>> &mat) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (isSafe(ni, nj, mat)) mat[ni][nj] = -1;
                }
            }
        }
    }
    for (auto &row : mat)
        for (int &cell : row)
            if (cell == -1) cell = 0;
}

int shortestSafePath(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
        if (mat[i][0] == 1) {
            q.push({i, 0});
            dist[i][0] = 0;
        }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isSafe(nx, ny, mat) && dist[x][y] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; i++)
        if (mat[i][n - 1] == 1) ans = min(ans, dist[i][n - 1]);

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}};
    markUnsafeCells(mat);
    int res = shortestSafePath(mat);
    cout << (res == -1 ? "No Safe Path" : to_string(res));
}

// Shortest Safe Route in a Path with Landmines