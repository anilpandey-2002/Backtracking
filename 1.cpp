#include <iostream>
#include <vector>
using namespace std;

void findPaths(vector<vector<int>> &mat, int x, int y, vector<int> &current, vector<vector<int>> &result) {
    int m = mat.size(), n = mat[0].size();
    if (x == m - 1 && y == n - 1) {
        current.push_back(mat[x][y]);
        result.push_back(current);
        current.pop_back();
        return;
    }

    current.push_back(mat[x][y]);
    if (x + 1 < m) findPaths(mat, x + 1, y, current, result);
    if (y + 1 < n) findPaths(mat, x, y + 1, current, result);
    current.pop_back();
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result;
    vector<int> current;

    findPaths(mat, 0, 0, current, result);

    for (auto &path : result) {
        for (int x : path) cout << x << " ";
        cout << "\n";
    }
}
//  Print All Possible Paths from Top Left to Bottom Right of an m x n Matrix