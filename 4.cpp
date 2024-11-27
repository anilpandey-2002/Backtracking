#include <iostream>
#include <vector>
using namespace std;

bool isKPartitionPossibleUtil(vector<int> &arr, vector<int> &subsetSum, vector<bool> &taken, int subset, int k, int idx) {
    if (subsetSum[subset] == 0) return true;

    for (int i = idx; i < arr.size(); i++) {
        if (!taken[i] && subsetSum[subset] >= arr[i]) {
            taken[i] = true;
            subsetSum[subset] -= arr[i];
            if (isKPartitionPossibleUtil(arr, subsetSum, taken, subset, k, i + 1)) return true;
            taken[i] = false;
            subsetSum[subset] += arr[i];
        }
    }
    return false;
}

bool isKPartitionPossible(vector<int> &arr, int k) {
    int n = arr.size(), sum = 0;
    for (int x : arr) sum += x;
    if (sum % k != 0) return false;

    vector<int> subsetSum(k, sum / k);
    vector<bool> taken(n, false);
    return isKPartitionPossibleUtil(arr, subsetSum, taken, k - 1, k, 0);
}

int main() {
    vector<int> arr = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout << (isKPartitionPossible(arr, k) ? "Yes" : "No");
}
// Partition of a Set into k Subsets with Equal Sum