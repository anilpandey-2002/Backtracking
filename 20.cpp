#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int> &arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] > sum) return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << (isSubsetSum(arr, arr.size(), sum) ? "Yes" : "No");
}
