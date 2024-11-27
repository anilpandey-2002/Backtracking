#include <iostream>
#include <unordered_map>
using namespace std;

bool isValidMapping(unordered_map<char, int> &map, string a, string b, string c) {
    int num1 = 0, num2 = 0, num3 = 0;
    for (char ch : a) num1 = num1 * 10 + map[ch];
    for (char ch : b) num2 = num2 * 10 + map[ch];
    for (char ch : c) num3 = num3 * 10 + map[ch];
    return num1 + num2 == num3;
}

void solveCrypto(string a, string b, string c, unordered_map<char, int> &map, vector<bool> &used, int idx) {
    if (idx == map.size()) {
        if (isValidMapping(map, a, b, c)) {
            for (auto &p : map) cout << p.first << " = " << p.second << ", ";
            cout << "\n";
        }
        return;
    }
    auto it = map.begin();
    advance(it, idx);
    char ch = it->first;
    for (int i = 0; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            map[ch] = i;
            solveCrypto(a, b, c, map, used, idx + 1);
            used[i] = false;
        }
    }
}

int main() {
    string a = "SEND", b = "MORE", c = "MONEY";
    unordered_map<char, int> map;
    vector<bool> used(10, false);
    for (char ch : a + b + c) map[ch] = -1;
    solveCrypto(a, b, c, map, used, 0);
}
// Cryptarithmetic Puzzle