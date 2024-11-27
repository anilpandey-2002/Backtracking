#include <iostream>
#include <algorithm>
using namespace std;

void printPermutations(string s, int l, int r) {
    if (l == r) {
        cout << s << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        printPermutations(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main() {
    string s = "ABC";
    printPermutations(s, 0, s.size() - 1);
}
//  Print All Permutations of a Given String