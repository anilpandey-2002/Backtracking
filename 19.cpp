#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

void tugOfWarUtil(vector<int> &arr, vector<bool> &currSet, int idx, int n, int count, int currSum, int totalSum, int &minDiff, vector<bool> &resultSet) {
    if (count == n / 2) {
        int diff = abs(totalSum - 2 * currSum);
        if (diff < minDiff) {
            minDiff = diff;
            resultSet = currSet;
        }
        return;
    }
    if (idx >= n) return;

    currSet[idx] = true;
    tugOfWarUtil(arr, currSet, idx + 1, n, count + 1, currSum + arr[idx], totalSum, minDiff, resultSet);
    currSet[idx] = false;
    tugOfWarUtil(arr, currSet, idx + 1, n, count, currSum, totalSum, minDiff, resultSet);
}

void tugOfWar(vector<int> &arr) {
    int n = arr.size();
    vector<bool> currSet(n, false), resultSet(n, false);
    int totalSum = 0, minDiff = INT_MAX;
    for (int x : arr) totalSum += x;

    tugOfWarUtil(arr, currSet, 0, n, 0, 0, totalSum, minDiff, resultSet);

    cout << "Set 1: ";
    for (int i = 0; i < n; i++) if (resultSet[i]) cout << arr[i] << " ";
    cout << "\nSet 2: ";
    for (int i = 0; i < n; i++) if (!resultSet[i]) cout << arr[i] << " ";
}
int main() {
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    tugOfWar(arr);
}
