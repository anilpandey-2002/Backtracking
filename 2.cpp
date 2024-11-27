#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void findPartitions(string &s, int start, vector<string> &current, vector<vector<string>> &result) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            findPartitions(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

int main() {
    string s = "aab";
    vector<vector<string>> result;
    vector<string> current;
    findPartitions(s, 0, current, result);

    for (auto &partition : result) {
        for (auto &p : partition) cout << p << " ";
        cout << "\n";
    }
}
//  Print Palindromic Partitions of a String