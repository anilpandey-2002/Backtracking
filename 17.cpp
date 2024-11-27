#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 8;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y, vector<vector<int>> &board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, vector<vector<int>> &board) {
    if (movei == N * N) return true;
    vector<pair<int, int>> nextMoves;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isSafe(nx, ny, board))
            nextMoves.push_back({nx, ny});
    }
    sort(nextMoves.begin(), nextMoves.end(), [&](pair<int, int> a, pair<int, int> b) {
        int cntA = 0, cntB = 0;
        for (int k = 0; k < 8; k++) {
            cntA += isSafe(a.first + dx[k], a.second + dy[k], board);
            cntB += isSafe(b.first + dx[k], b.second + dy[k], board);
        }
        return cntA < cntB;
    });
    for (auto [nx, ny] : nextMoves) {
        board[nx][ny] = movei;
        if (solveKTUtil(nx, ny, movei + 1, board)) return true;
        board[nx][ny] = -1;
    }
    return false;
}

void printBoard(vector<vector<int>> &board) {
    for (auto row : board) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0;
    if (solveKTUtil(0, 0, 1, board))
        printBoard(board);
    else
        cout << "No Solution";
}
//  Warnsdorff’s Algorithm (Knight's Tour Problem)