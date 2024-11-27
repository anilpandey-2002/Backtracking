#include <iostream>
#include <regex>
using namespace std;

bool matchPattern(string s, string pattern) {
    regex re(pattern);
    return regex_match(s, re);
}

int main() {
    string s = "abc123";
    string pattern = "[a-z]+[0-9]+";
    cout << (matchPattern(s, pattern) ? "Matched" : "Not Matched");
}
//  Match a Pattern and String using Regular Expression