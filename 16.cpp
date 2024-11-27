#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main() {
    unordered_set<string> dict = {"leet", "code"};
    string s = "leetcode";
    cout << (wordBreak(s, dict) ? "Yes" : "No");
}
//  Word Break Problem