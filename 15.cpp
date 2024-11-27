#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') {
            if (count == 0) return false;
            count--;
        }
    }
    return count == 0;
}

void removeInvalidParentheses(string s) {
    unordered_set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    bool found = false;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (isValid(curr)) {
            cout << curr << "\n";
            found = true;
        }
        if (found) continue;

        for (int i = 0; i < curr.size(); i++) {
            if (curr[i] != '(' && curr[i] != ')') continue;
            string temp = curr.substr(0, i) + curr.substr(i + 1);
            if (!visited.count(temp)) {
                q.push(temp);
                visited.insert(temp);
            }
        }
    }
}

int main() {
    string s = "()())()";
    removeInvalidParentheses(s);
}
// Remove Invalid Parentheses